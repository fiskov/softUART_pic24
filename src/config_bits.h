#ifndef CONFIG_BIT_H
#define	CONFIG_BIT_H

  #if defined(__PIC24F16KA102__)
  // FBS
  #pragma config BWRP = OFF               // Table Write Protect Boot (Boot segment may be written)
  #pragma config BSS = OFF                // Boot segment Protect (No boot program Flash segment)

  // FGS
  #pragma config GWRP = OFF               // General Segment Code Flash Write Protection bit (General segment may be written)
  #pragma config GCP = OFF                // General Segment Code Flash Code Protection bit (No protection)

  // FOSCSEL
  #pragma config FNOSC = FRC              // Oscillator Select (Fast RC oscillator (FRC))
  #pragma config IESO = OFF                // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-Speed Start-up enabled))

  // FOSC
  #pragma config POSCMOD = NONE           // Primary Oscillator Configuration bits (Primary oscillator disabled)
  #pragma config OSCIOFNC = ON            // CLKO Enable Configuration bit (CLKO output disabled; pin functions as port I/O)
  #pragma config POSCFREQ = HS            // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency greater than 8 MHz)
  #pragma config SOSCSEL = SOSCLP         // SOSC Power Selection Configuration bits (Secondary oscillator configured for high-power operation)
  #pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)

  // FWDT
  #pragma config WDTPS = PS512          // Watchdog Timer Postscale Select bits (1:32,768)
  #pragma config FWPSA = PR32            // WDT Prescaler (WDT prescaler ratio of 1:128)
  #pragma config FWDTEN = ON             // Watchdog Timer Enable bit 
  #pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Standard WDT selected; windowed WDT disabled)

  // FPOR
  #pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware; SBOREN bit disabled)
  #pragma config PWRTEN = ON              // Power-up Timer Enable bit (PWRT enabled)
  #pragma config I2C1SEL = PRI            // Alternate I2C1 Pin Mapping bit (Default location for SCL1/SDA1 pins)
  #pragma config BORV = V18               // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (1.8V))
  #pragma config MCLRE = ON               // MCLR Pin Enable bit (MCLR pin enabled; RA5 input pin disabled)

  // FICD
  #pragma config ICS = PGx1               // ICD Pin Placement Select bits (PGC1/PGD1 are used for programming and debugging the device)

  // FDS
  #pragma config DSWDTPS = DSWDTPSF       // Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))
  #pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select bit (DSWDT uses LPRC as reference clock)
  #pragma config RTCOSC = LPRC            // RTCC Reference Clock Select bit (RTCC uses LPRC as reference clock)
  #pragma config DSBOREN = OFF            // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR disabled in Deep Sleep)
  #pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable bit (DSWDT disabled)

  #else
  // FBS 
  #pragma config BWRP = OFF               // Boot Segment Write Protect (Disabled)
  #pragma config BSS = OFF                // Boot segment Protect (No boot program flash segment)

  // FGS
  #pragma config GWRP = OFF               // General Segment Write Protect (General segment may be written)
  #pragma config GSS0 = OFF               // General Segment Code Protect (No Protection)

  // FOSCSEL
  #pragma config FNOSC = FRCPLL           // Oscillator Select (8MHz FRC oscillator)
  #pragma config SOSCSRC = DIG            // SOSC Source Type (Analog Mode for use with crystal)
  #pragma config LPRCSEL = HP             // LPRC Oscillator Power and Accuracy (Low Power, Low Accuracy Mode)
  #pragma config IESO = OFF                // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-speed Start-up enabled))

  // FOSC
  #pragma config POSCMOD = NONE         // Primary Oscillator Configuration bits (Primary oscillator disabled)
  #pragma config OSCIOFNC = OFF           // CLKO Enable Configuration bit (CLKO output disabled)
  #pragma config POSCFREQ = HS            // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency between 100kHz and 8MHz)
  #pragma config SOSCSEL = SOSCLP         // SOSC Power Selection Configuration bits (Secondary Oscillator configured for low-power operation)
  #pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)

  // FWDT
  #pragma config WDTPS = PS512          // Watchdog Timer Postscale Select bits (1:32768)
  #pragma config FWPSA = PR32            // WDT Prescaler bit (WDT prescaler ratio of 1:128)
  #pragma config FWDTEN = ON              // Watchdog Timer Enable bits (WDT enabled in hardware)
  #pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Standard WDT selected(windowed WDT disabled))

  // FPOR
  #pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware, SBOREN bit disabled)
  #pragma config LVRCFG = OFF             // Low Voltage Regulator Configuration bit (Low Voltage regulator is not available)
  #pragma config PWRTEN = ON              // Power-up Timer Enable bit (PWRT enabled)
  #pragma config I2C1SEL = PRI            // Alternate I2C1 Pin Mapping bit (Use Default SCL1/SDA1 Pins For I2C1)
  #pragma config BORV = V20               // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (2.0V))
  #pragma config MCLRE = ON               // MCLR Pin Enable bit (RA5 input pin disabled,MCLR pin enabled)

  // FICD
  #pragma config ICS = PGx1               // ICD Pin Placement Select bits (EMUC/EMUD share PGC2/PGD2)

  // FDS
  #pragma config DSWDTPS = DSWDTPSF       // Deep Sleep Watchdog Timer Postscale Select bits (1:2048 (2.1 Seconds))
  #pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select bit (DSWDT uses Low Power RC Oscillator (LPRC))
  #pragma config DSBOREN = OFF            // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR disabled in Deep Sleep)
  #pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable bit (DSWDT disabled)

  // #pragma config statements should precede project file includes.
  // Use project enums instead of #define for ON and OFF.
  #endif 

#include <xc.h>

#endif	/* CONFIG_BIT_H */



