/**
 * @file uart.c
 * @author Group DHT22
 * @source Jan Haffmueller
 * @brief Initializing the UART
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "uart.h"           
#include "uart_dsPIC.h"     
#define BUFFER_LENGTH 100               // Length of Ring Buffer

/********* Global Buffer ************/
struct RingBuffer{
    unsigned char Buffer[BUFFER_LENGTH];
    unsigned char BufCnt;               // Content count
    unsigned char BufInPtr;             // Pointer to next write location
    unsigned char BufOutPtr;            // Pointer to next read location
};

struct RingBuffer TxBuf;
struct RingBuffer RxBuf;

/****** UART Buffer Functions ******/

void CommPutRxChar(unsigned char data)
// This function places the byte "data" in the Buffer. 
// It is called from the receive ISR.
{
    CommRxIntDis();         // Disable RX IRQ
        
    if (RxBuf.BufCnt != BUFFER_LENGTH)      // Buffer Not Full
    {
        RxBuf.Buffer[RxBuf.BufInPtr]=data;  // Write character into buffer

        RxBuf.BufCnt++;                     // Increment buffer counter
        if (RxBuf.BufInPtr == BUFFER_LENGTH-1)  // End of buffer array?
            RxBuf.BufInPtr = 0;             // Yes, point to beginning of buffer
        else
            RxBuf.BufInPtr++;               // No, increment pointer       
    }
    CommRxIntEn();         // Enable RX IRQ
}    

void CommInit(void)
// Initialises the RX & TX Ring Buffer
{
    TxBuf.BufCnt = 0;       // Reset counter
    TxBuf.BufInPtr = 0;     // First location
    TxBuf.BufOutPtr = 0;    // First location
    
    RxBuf.BufCnt = 0;       // Reset counter
    RxBuf.BufInPtr = 0;     // First location
    RxBuf.BufOutPtr = 0;    // First location
}    

unsigned char CommGetChar(void)
// Reads a byte from the RX Buffer and returns it to the caller funct.
// This is called from the user app
{
    unsigned char data;
    
    CommRxIntDis();         // Disable RX IRQ
    
    if (RxBuf.BufCnt != 0)                  // Buffer empty?
    {                                       // No
        data = RxBuf.Buffer[RxBuf.BufOutPtr]; // Read from buffer
         
        RxBuf.BufCnt--;                         // Decrement counter
     
        if (RxBuf.BufOutPtr == BUFFER_LENGTH - 1)    // End of buffer?
            RxBuf.BufOutPtr = 0;                 // Yes, point to beginning
        else               
            RxBuf.BufOutPtr++;                   // No, increment pointer
    }
    CommRxIntEn();
 
    return(data);  
}


unsigned char CommIsEmpty(void)
// Checks if the RXRing Buffer is empty.
// Returns '1' for empty and '0' for not empty
{
    unsigned char data;   
    
    CommRxIntDis();         // Disable RX IRQ
    
    if (RxBuf.BufCnt != 0)  // Buffer empty?
    {                       // No
        data = 0;           // Ring Buffer not empty
    }
    else
    {
        data = 1;
    }    
    CommRxIntEn();
 
    return(data);  
}    

unsigned char CommGetTxChar(void)
// This function reads a byte from the TX Ring Buffer and returns it
// to the calling function.
// It is to be called from the TX ISR
{
    unsigned char data;
       
    if (TxBuf.BufCnt != 0)                  // Buffer empty?
    {                                       // No
        data = TxBuf.Buffer[TxBuf.BufOutPtr]; // Read from buffer
         
        TxBuf.BufCnt--;                         // Decrement counter
        if (TxBuf.BufCnt == 0)                  // last byte, now empty
            CommTxIntDis();                     // Stop Tx IRQ 
     
        if (TxBuf.BufOutPtr == BUFFER_LENGTH - 1)    // End of buffer?
            TxBuf.BufOutPtr = 0;                 // Yes, point to beginning
        else               
            TxBuf.BufOutPtr++;                   // No, increment pointer
    }
    return(data);      
}    

void CommPutChar(unsigned char data)
// Writes the data byte into the TX Ring Buffer
{
    CommTxIntDis();         // Disable RX IRQ
        
    if (TxBuf.BufCnt != BUFFER_LENGTH)      // Buffer Not Full
    {                                       // No
        TxBuf.Buffer[TxBuf.BufInPtr]=data;  // Write character into buffer
       
       // Here is a need to start the TX IRQ. This can be done in various ways.
       // One way is to check for an empty Ring Buffer and if it is empty to 
       // set the TX IRQ flag to cause an IRQ. This may work with UART without
       // a FIFO, however on UARTs with FIFO (e.g. dsPIC) it does not.
       // The flaw is that while the Ring Buffer is empty, the FIFO may be full.
       // Triggering an IRQ wenn the FIFO is full will cause that the data byte
       // is read from the Ring Buffer, but not written to the UART FIFO (as it 
       // is full). 
       // The solution here is to check if the UART FIFO is full. If not (i.e.
       // there is space on the UART FIFO), then a TX IRQ can safely be triggered.
       // If the UART FIFO is full, then the no TX IRQ needs to be triggered as 
       // one will be triggered next time a byte has been send.
       if (CommTxFull() != 1)               // UART FIFO full
            CommTxIntSet();                 // No, set TX IRQ Flag
        TxBuf.BufCnt++;                     // Increment buffer counter
        if (TxBuf.BufInPtr == BUFFER_LENGTH-1)  // End of buffer array?
            TxBuf.BufInPtr = 0;             // Yes, point to beginning of buffer
        else
            TxBuf.BufInPtr++;               // No, increment pointer       
    }
    CommTxIntEn();         // Enable RX IRQ
}        

void CommPutString(char *str_data)
// Writes a string into the TX Ring Buffer
{
     
    while(*str_data)
    {
        CommPutChar(*str_data);
        str_data++;
    }            
}    

/**
 * @brief As long as the ring buffer is not empty, the characters
 * are stored in a string
 * 
 * @param stringArray 
 */
 void CommGetString(char *stringArray) {
     int i = 0;
     unsigned char currentInput = 0;
     while (CommIsEmpty() != 1 ) { // sizeof returns the size in bytes and not the number of elements, but since it is character here, it is the same.
         currentInput = CommGetChar();
         if (currentInput == '\n' || currentInput == '\r' || currentInput == 'q') {
             return;
         }
         stringArray[i] = currentInput;
         i++;
     }
     return;
 }


/**************************************************************************************************************************************************/
// Convert the string to a float and check if the value is in the range of 0 to 100
// TODO: Screen shot 7
 void CommGetSetBorderValue(float *border, int *iState) {
    if (CommIsEmpty() != 1){  // Echo of RX
        char buffer[30] = "The new value is: ";
        char inputBuffer[10] = {0};
        float currentvalue = 0;
        CommGetString(inputBuffer);
        currentvalue = atof(inputBuffer); // atof converts a string to a float
        
        if (currentvalue > 0 && currentvalue < 100) { // check if the value is in the range of 0 to 100
            *border = currentvalue;
            snprintf(buffer, sizeof(buffer), "%.1f\n", (double)*border);
            CommPutString(buffer);
            *iState = 1;
        } else {
            CommPutString("The value is not in the range of 0 to 100. \nPlase try again. \n");
        }
    }
    return;
 }

// Switch case for change the values of the borders
void ChangeValue(int iState, float *a_borderYellowHum, float *a_borderRedHum) {

/**Borders in  ASCCI table
 * Y = 89
 * R = 82
 * Any other input is an error
*/
    switch (iState) {
                case 0: // wait for first input
                    if ((CommIsEmpty() != 1) && (89 || 82)){  // Echo of RX
                        iState = CommGetChar();
                    }else {
                        iState = 4;
                    }
                    break;
                case 1:
                    CommPutString("To change the middle border value type Y (yellow light) \nand to change the upper border Value type R (red light).\n");
                    iState = 0;
                    break;
                case 89: // Y changes the middle border value
                    CommPutString("please insert the new value for the middle border for the humidity: \n");
                    iState = 2;
                case 2:
                    CommGetSetBorderValue(a_borderYellowHum, &iState);
                    if (a_borderYellowHum < 0){
                        iState = 5;
                    }else {
                        break;
                    }
                case 82: // R changes the upper border value
                    CommPutString("please insert the new value for the upper border for the humidity: \n");
                    iState = 3;
                case 3:
                    CommGetSetBorderValue(a_borderRedHum, &iState);
                    break;
                case 4:
                    CommPutString("Wrong input! You are only allowed to enter Y or R! \nPlease try again.\n");
                    iState = 0;
                    break;
                case 5:
                    CommPutString("Wrong input! You are only allowed to enter numbers between 0 and 100! \nPlease try again.\n");
                    iState = 0;
                    break;


                default:
                    // if (CommIsEmpty() != 1){  // Echo of RX
                    //     iState = CommGetChar();
                    // }
                    break;
            }
}