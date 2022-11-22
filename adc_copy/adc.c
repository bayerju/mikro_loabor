#include "xc.h" //Einbindung der Prozessor Datei

#define N_12 1 //12 bit adc , wir haben einen 12 bit adc daher 1
#define N_10 0 //10 bit adc
#define ADC_PRIO 2 // Priorit�t vom ADC
#define ON 1 
#define OFF 0
#define BUFFER_LENGTH 10 // maximum of 255

unsigned int adc_buffer [BUFFER_LENGTH];
unsigned char adc_flag = 0;

void adc_irq_activation(unsigned char onoff);

void __attribute__((__interrupt__, no_auto_psv)) _ADC1Interrupt(void)
{   
    //Interrupt Service Routine muss hier noch rein//
    static unsigned char i = 0;
    adc_buffer[i] = ADC1BUF0;
    i++;
    if (i== BUFFER_LENGTH) i =0;
    adc_flag =1;                    //ADC ist bereit und wird gesetzt
    IFS0bits.AD1IF = 0;             //Clear AD1 Interrupt Flag vom anfang

}

void setupAdc() {
    /*
     Einstellung des ADC Moduls f�r die Benutzung
     * 
     * fa= FOSC/(2*(M+1)*(N+3)  N =
     
     
     */
    AD1PCFGLbits.PCFG9 = 0; //AN9 analog Spannungs bin gesetzt
 
    AD1CON1bits.ADON = 0;  //Stopp des ADC Molduls
    
    AD1CON1bits.AD12B = N_12; //12 Bit Channel; Siehe variable Oben
    AD1CON2bits.CHPS = 0b00;  // Convert Channel 0
    
    AD1CHS0bits.CH0SA = 0b01001;  //AN9 ist der Input hier eingestellt
    AD1CHS0bits.CH0NA = 0;          
    
    AD1PCFGLbits.PCFG0 = 0;     //AN0 in analoge mode
    TRISAbits.TRISA0 = 1;
    
    AD1CON2bits.VCFG = 0;
    
    AD1CON3bits.ADRC = 1;           //System clock --> ADC clock
    AD1CON1bits.SSRC = 0b010;       //Timer 3 als Trigger
    AD1CON3bits.SAMC = 0;          //Internal SAMC counter, not used
    
    AD1CON1bits.FORM = 0b00;
    AD1CON1bits.ASAM = 1;
    
    AD1CON1bits.ADSIDL = 0;     //In idle Mode continues
    
    //Einf�gen der Interrupts
    IPC3bits.AD1IP = ADC_PRIO;  //Priorit�t im Header festgelegt
    IEC0bits.AD1IE = 0;         //disable the ADC Interrupt
}

void adc_irq_activation(unsigned char onoff){
    //En oder Disable den ADC IRQ
    // 1 = anschalten enable
    // 0 = ausschaltden des ADC disable
    if (onoff == ON){
        IFS0bits.AD1IF = 0; //clear ADC Interrupt Flag
        IEC0bits.AD1IE = 1; //enable the ADC Interrupt
    }
    else{
        IEC0bits.AD1IE = 0; //disable the ADC Interrupt
    }
}

void adc_start(void){
    adc_irq_activation(ON);
    AD1CON1bits.ADON = 1;       //Einschalten des ADC Wandler
}

void adc_stop(void){
    adc_irq_activation(OFF);
    AD1CON1bits.ADON = 0;       //Ausschalten des ADC wandlers
} 
 
// Funktion f�r den Buffer schreiben die genutzt wird um Daten auszulesen
