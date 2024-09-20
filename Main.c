/*
 * File:   Main.c
 * Author: Lenovo
 *
 * Created on August 23, 2024, 10:52 AM
 */

/* Uklju?ivanje potrebnih zaglavlja */
#include "IO_ports.h"
#include "UART.h"
#include "MATH.h"
#include "Interrupts.h"
#include "Timer.h"
#include <p30f4011.h>
#include <libpic30.h>


/* Izbor odgovarajuceg moda oscilatora */
//_FOSC(CSW_FSCM_OFF & XT_PLL8);                                                // Koristi externi FRC oscilator
_FOSC(FRC & CSW_FSCM_OFF);                                                      // Koristi interni FRC oscilator
_FWDT(WDT_OFF);                                                                 // Watchdog Timer isklju?en
_FBORPOR(MCLR_EN & PWRT_OFF);                                                   // MCLR pin bi?e kori??en za reset spolja, PWRT je isklju?en
_FGS(CODE_PROT_OFF);                                                            // Code protection isklju?en


/* Definicije konstanti za LED - makro zamene */
#define LED1        LATB_bits.LATB0                                             // Makro zamena za LED1
#define LED2        LATB_bits.LATB1                                             // Makro zamena za LED2
#define LED3        LATB_bits.LATB2                                             // Makro zamena za LED3
#define LED4        LATB_bits.LATB3                                             // Makro zamena za LED4

/*  Definicija konstanti za osclator */
#define FCY         7370000                                                     // Definicija frekvencije za funkciju delay_ms(Fosc / 2)
//#define FRC         7370000                                                   //Makro zamena za takt internog oscilatora
#define BAUDRATE    4800                                                        //Makro zamena za brzinu prenosa podataka
#define BAUD_CONST  ((FCY / (16 * BAUDRATE)) - 1)                               // Makro zamena za izracunatu brzinu prenosa podataka

// Definicije konstanti - makro zamene
#define F_CLK                   7370000                                         // Instrukcijski takt DSP-a 7.37 MHz
#define F_S                     1                                               // Ucestanost brojanja timer periferije
#define N                       256                                             // Preskaler 1:256
#define TIM1_PERIOD             F_CLK/F_S/N                                     // Punjenje za period registar tajmer periferije



// Funkcija za inicijalizaciju TIMER1
void Timer1Init()
{
    clrReg16(T1CON_REG);                                                        // Iskljucenje TIMER1 periferije
    clrReg16(IEC0_REG);                                                         // Zabrana generisanja prekida
    clrReg16(TMR1_REG);                                                         // Reset inkrementalnog brojaca TIMER1 periferije
          
    clrReg16Bits(T1CON_REG,T1CON_TCS);                                          // Izbor TIMER moda rada: ulazni clock za brojanje je interni clock periferije (Fosc/4)

    IPC0_bits.T1IP = 7;                                                         // Izbor prioriteta prekida TIMER1 periferije: najvisi maskirajuci prioritet - 7
    IFS0_bits.T1IF = 0;                                                         // Reset flag-a za prekidnu rutinu TIMER1 periferije
    IEC0_bits.T1IE = 1;                                                         // Dozvola generisanja prekida TIMER1 periferije
         
    setReg16(PR1_REG,TIM1_PERIOD);                                              // Upis periode za merenje vremena TIMER1 periferije
        
    setReg16Bits(T1CON_REG,T1CON_PSC256);                                       // Izbor delitelja frekvencije TIMER1 periferije: 1:256
    setReg16Bits(T1CON_REG,T1CON_TON);                                          // Ukljucenje TIMER1 periferije
}

/* Funkcija za definiciju da li su pinovi izlazni ili ulazni */
void IO_Init(void)
{  
    TRISB_REG = 0xFFF0;                                                         // Prva ?etiri bita postavljamo kao izlaz, ostali ostaju kao ulazni
}

/*Funkcija za inicijalizaciju UART2 periferije - napomena RX i TX su RF4 i RF5*/
void UARTinit(void)
{           
    clrReg16Bits(U2MODE_REG, UMODE_UARTEN);                                     // Iskljucenje UART2 modula

    IEC1_bits.U2RXIE = 0;                                                       // Zabrana (privremena) generisanja prekida RX UART2 modula
    IEC1_bits.U2TXIE = 0;                                                       // Zabrana generisanja prekida TX UART2 modula
    IFS1_bits.U2RXIF = 0;                                                       // Reset flag-a za prekidnu rutinu RX UART2 modula
    IFS1_bits.U2TXIF = 0;                                                       // Reset flag-a za prekidnu rutinu TX UART2 modula
    
    IEC1_bits.U2RXIE = 1;                                                       // Dozvola generisanja prekida RX UART2 modula
 
    U2BRG_REG = BAUD_CONST;                                                     // Upis BaudRate u registar U2BRG
    
    setReg16Bits(U2MODE_REG, UMODE_USIDL);                                      // Prekid rada modula u Idle stanju                                      
    clrReg16Bits(U2MODE_REG, UMODE_WAKE);                                       // Onemogucen Wake-up
    clrReg16Bits(U2MODE_REG, UMODE_LPBACK);                                     // Hardverski LOOPBACK onemogucen
    clrReg16Bits(U2MODE_REG, UMODE_ABAUD);                                      // Auto baud onemogucen
    setReg16Bits(U2MODE_REG, UMODE_PDSEL0);                                     // Podaci sirine 8b bez parity logike
    clrReg16Bits(U2MODE_REG, UMODE_STSEL);                                      // Konfiguracija sa jednim stop bitom
    setReg16Bits(U2MODE_REG, UMODE_UARTEN);                                     // Ukljucene UART2 periferije
    
    clrReg16Bits(U2STA_REG, USTA_UTXISEL);                                      // Prekid kada je karakter prenesen do Tx PISO registra
    clrReg16Bits(U2STA_REG, USTA_UTXBRK);                                       // U2TX pin u normalnom modu rada
    setReg16Bits(U2STA_REG, USTA_UTXEN);                                        // Omogucenje prenosa na Tx liniji - alternativna funkcija pina

    setReg16Bits(U2STA_REG, USTA_URXISEL1);                                     // Setovnaje prekidnog flag-a na RX prijem svakog karaktera 
    clrReg16Bits(U2STA_REG, USTA_ADDEN);                                        // Onemogucen mod za detekciju adrese
    
    U2STA_bits.OERR = 0;                                                        // Prijemni bafer je prazan
}

/************************************************************************************************************************************************************/
/* TIMER1 prekidna rutina - promena stanja LED, mikrokontroler oslobodjen softverskog merenja vremena                                                       */
/************************************************************************************************************************************************************/
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{  
	LED1 = LED1 ^ 1;                                                            // Promena stanja LED1 - toogle
    
    IFS0_bits.T1IF = 0;                                                         // Brisanje statusnog flag-a za TIM1 u okviru prekidne periferije
}

/************************************************************************************************************************************************************/
/* Prekidna rutina za RX UART2                                                                                                                              */
/************************************************************************************************************************************************************/
void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void) 
{
    char receivedChar;
    
    if (U2STAbits.OERR == 1)                                                    // Proveri da li postoji OERR (Overrun Error)
    {
        U2STAbits.OERR = 0;                                                     // Resetuj OERR
    }
    while (U2STAbits.URXDA == 1)                                                // Proveri da li ima podataka u baferu
    {
        if (U2STAbits.FERR == 0 && U2STAbits.PERR == 0)                         // Proveri framing error (FERR) i paritetne gre?ke (PERR)
        { 
            receivedChar = U2RXREG;                                             // U?itaj primljeni karakter - Ako nema gre?aka
        
            LED2 = LED2 ^ 1;                                                    // Signaliziraj prijem karaktera

            int num = (int)(receivedChar - '0');                                // Dekodiranje ASCII karaktera (pretvori karakter '0' ili '1' u broj)
        
            if (num == 1)                                                       // Kontroli?i LED3 na osnovu primljenog karaktera
            {
                LED3 = 1;                                                       // Upali LED3
            } 
            else if (num == 0) 
            {
                LED3 = 0;                                                       // Ugasi LED3
            }
        }
    }   

    IFS1bits.U2RXIF = 0;                                                        // Resetuj prekidni flag za RX
}

/* Glavni program */
int main(void)
{
    IO_Init();  
    UARTinit();
    Timer1Init();                                                               // Poziv obicne funkcije za inicijalizaciju TIMER1 periferije
    
	//LED1 = 1;   
    //LED2 = 1; 
    //LED3 = 1; 
    LED4 = 1; 

    while(1)
    {
        // Glavna petlja
    }

    return 0;
}

