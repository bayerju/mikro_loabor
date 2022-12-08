
/**************************************************************************************
 Source: https://simple-circuit.com/pic-mcu-ssd1306-dht22-mikroc/
  Interfacing PIC16F887 microcontroller with SSD1306 OLED (128x64 Pixel) and
    DHT22 (AM2302) sensor.
  C Code for mikroC PRO for PIC compiler
  Internal oscillator used @ 8MHz
  Configuration words: CONFIG1 = 0x2CD4
                       CONFIG2 = 0x0700
  This is a free software with NO WARRANTY.
  https://simple-circuit.com/
 
***************************************************************************************/
 
// SSD1306 OLED reset pin definition
#define SSD1306_RST       RD4_bit
#define SSD1306_RST_DIR   TRISD4_bit
 
// DHT22 sensor connection (here data pin is connected to pin RD5)
#define DHT22_PIN         RD5_bit
#define DHT22_PIN_DIR     TRISD5_bit
 
 
#include <SSD1306.c>   // include SSD1306 OLED driver source code
 
char Temperature[] = "000.0 C";
char Humidity[]    = "000.0 %";
 
unsigned short T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum;
unsigned int   Temp, RH;
 
char degree[] = {0, 7, 5, 7, 0};    // degree symbol char
 
// send start signal to the sensor
void Start_Signal(void)
{
  DHT22_PIN     = 0;   // connection pin output low
  DHT22_PIN_DIR = 0;   // configure connection pin as output
  delay_ms(25);        // wait 25 ms
  DHT22_PIN     = 1;   // connection pin output high
  delay_us(25);        // wait 25 us
  DHT22_PIN_DIR = 1;   // configure connection pin as input
}
 
// check sensor response
unsigned short Check_Response()
{
  TMR1H = TMR1L = 0;    // reset Timer1
  TMR1ON_bit    = 1;    // enable Timer1 module
  
  // wait until DHT22_PIN becomes high (checking of 80µs low time response)
  while(!DHT22_PIN && TMR1L < 100) ;
 
    if(TMR1L >= 100)  // if response time >= 100µS  ==> response error
      return 0;       // return 0 (device has a problem with response)
 
  else
  {
    TMR1H = TMR1L = 0;    // reset Timer1
    
    // wait until DHT22_PIN becomes low (checking of 80µs high time response)
    while(DHT22_PIN && TMR1L < 100) ;
 
    if(TMR1L >= 100)  // if response time >= 100µS  ==> response error
      return 0;       // return 0 (device has a problem with response)
 
    else
      return 1;   // return 1 (response OK)
  }
}
 
// data read function
unsigned short Read_Data(unsigned short* dht_data)
{
  short i;
  *dht_data = 0;
  
  for(i = 0; i < 8; i++) {
    TMR1H = TMR1L = 0;    // reset Timer1
    
    while(!DHT22_PIN)     // wait until DHT22_PIN becomes high
    {
      if(TMR1L > 100)     // if low time > 100  ==>  Time out error (Normally it takes 50µs)
        return 1;
    }
    
    TMR1H = TMR1L = 0;    // reset Timer1
    
    while(DHT22_PIN)    // wait until DHT22_PIN becomes low
      if(TMR1L > 100)   // if high time > 100  ==>  Time out error (Normally it takes 26-28µs for 0 and 70µs for 1)
        return 1;       // return 1 (timeout error)
    
    if(TMR1L > 50)                   // if high time > 50  ==>  sensor sent 1
      *dht_data |= (1 << (7 - i));   // set bit (7 - i)
  }
  
  return 0;   // return 0 (data read OK)
 
}
 
// main function
void main() {
  OSCCON =  0x70;  // set internal oscillator to 8MHz
  T1CON  = 0x10;   // set Timer1 clock source to internal with 1:2 prescaler (Timer1 clock = 1MHz)
  TMR1H = TMR1L = 0;  // reset Timer1
 
  delay_ms(1000);   // wait half a second
 
  I2C1_Init(400000);    // initialize I2C communication with clock frequency of 400KHz
 
  // initialize the SSD1306 OLED with an I2C addr = 0x7A (default address)
  SSD1306_Init(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
 
  // clear the whole display
  SSD1306_ClearDisplay();
  
  SSD1306_GotoXY(3, 1);
  SSD1306_Print("DHT22 TEMPERATURE:");
  SSD1306_GotoXY(5, 6);
  SSD1306_Print("DHT22 HUMIDITY:");
 
  while(1) {
 
    Start_Signal();  // send a start signal to the sensor
 
    if(Check_Response())  // check if there is a response from sensor (if OK start reading humidity and temperature data)
    {   // response OK ==> read (and save) data from the DHT22 sensor and check time out errors
    
      Read_Data(&RH_Byte1);  // read humidity 1st byte and store its value in the variable RH_Byte1
      Read_Data(&RH_Byte2);  // read humidity 2nd byte and store its value in the variable RH_Byte2
      Read_Data(&T_Byte1);   // read temperature 1st byte and store its value in the variable T_Byte1
      Read_Data(&T_Byte2);   // read temperature 2nd byte and store its value in the variable T_Byte2
      Read_Data(&CheckSum);  // read checksum and store its value in the variable CheckSum
 
        // test if all data were sent correctly
        if(CheckSum == ((RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2) & 0xFF))
        {
          RH   = (RH_Byte1 << 8) | RH_Byte2;
          Temp = (T_Byte1  << 8) |  T_Byte2;
 
          if( RH >= 1000)
            Humidity[0]  = '1';
          else
            Humidity[0]  = ' ';
 
          if(Temp > 0x8000) {
            Temperature[0] = '-';
            Temp = Temp & 0x7FFF;
          }
          else
            Temperature[0] = ' ';
 
          Temperature[1]  = (Temp / 100) % 10 + '0';
          Temperature[2]  = (Temp / 10)  % 10 + '0';
          Temperature[4]  =  Temp        % 10 + '0';
          Humidity[1]     = (RH / 100)   % 10 + '0';
          Humidity[2]     = (RH / 10)    % 10 + '0';
          Humidity[4]     =  RH          % 10 + '0';
 
        }
 
        // checksum error
        else {
          Temperature[0] = Temperature[1] = Temperature[2] = Temperature[4] = 'E';
          Humidity[0]    = Humidity[1]    = Humidity[2]    = Humidity[4]    = 'E';
        }
 
    }
 
    // sensor response error (connection error)
    else {
      Temperature[0] = Temperature[1] = Temperature[2] = Temperature[4] = 'E';
      Humidity[0]    = Humidity[1]    = Humidity[2]    = Humidity[4]    = 'E';
    }
 
    // display the temperature
    SSD1306_GotoXY(8, 3);
    SSD1306_Print(Temperature);
    SSD1306_GotoXY(13, 3);
    SSD1306_PutCustomC(degree);      // put degree symbol ( ° )
    
    // display the relative humidity
    SSD1306_GotoXY(8, 8);
    SSD1306_Print(Humidity);
 
    TMR1ON_bit = 0;   // disable Timer1 module
    delay_ms(1000);   // wait 1 second between readings
 
  }
 
}
// end of code.