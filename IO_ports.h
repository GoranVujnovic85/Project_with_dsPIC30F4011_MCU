/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IO_PORTS_H
#define	IO_PORTS_H


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

// //-----------------------------------------------------------------------------------------------------------------------------------------------------------
// Makro definicije registarskih polja IO periferija za mikrokontroler dsPIC30F4011
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


// IO port B
#define TRISB_REG               (*((volatile int *) 0x02C6))  // Port B registar za definisanje smera podataka (ulazni/izlazni pin)
#define PORTB_REG               (*((volatile int *) 0x02C8))  // Port B registar za ?itanje podatka direktno sa pina
#define LATB_REG                (*((volatile int *) 0x02CA))  // Port B registar za ?itanje podatka iz latch flip flopa

// IO port B - polja bitova
typedef struct{
    unsigned TRISB0:1;
    unsigned TRISB1:1;
    unsigned TRISB2:1;
    unsigned TRISB3:1;
    unsigned TRISB4:1;
    unsigned TRISB5:1;
    unsigned TRISB6:1;
    unsigned TRISB7:1;
    unsigned TRISB8:1;
    unsigned :7;
;
} TRISBBITS_REG;

#define TRISB_bits              (*((volatile TRISBBITS_REG *) 0x02C6))  // Polje bitova za pode?avanje ulazno izlaznih pinova porta B

typedef struct{
    unsigned PORTB0:1;
    unsigned PORTB1:1;
    unsigned PORTB2:1;
    unsigned PORTB3:1;
    unsigned PORTB4:1;
    unsigned PORTB5:1;
    unsigned PORTB6:1;
    unsigned PORTB7:1;
    unsigned PORTB8:1;
    unsigned :7;
  
} PORTBBITS_REG;

#define PORTB_bits              (*((volatile PORTBBITS_REG *) 0x02C8))  // Polje bitova za upis/?itanje sa pina porta B

typedef struct{
    unsigned LATB0:1;
    unsigned LATB1:1;
    unsigned LATB2:1;
    unsigned LATB3:1;
    unsigned LATB4:1;
    unsigned LATB5:1;
    unsigned LATB6:1;
    unsigned LATB7:1;
    unsigned LATB8:1;
    unsigned LATB9:1;
    unsigned :7;
} LATBBITS_REG;

#define LATB_bits               (*((volatile LATBBITS_REG *) 0x02CA))  // Polje bitova za upis/?itanje sa LATCH registra porta B



// IO port C
#define TRISC_REG               (*((volatile int *) 0x02CC))                    // Port C registar za definisanje smera podataka (ulazni/izlazni pin)
#define PORTC_REG               (*((volatile int *) 0x02CE))                    // Port C registar za ?itanje podatka direktno sa pina
#define LATC_REG                (*((volatile int *) 0x02D0))                    // Port C registar za ?itanje podatka iz latch flip flopa

// IO port C - polja bitova
typedef struct{
  unsigned :13;
  unsigned TRISC13:1;
  unsigned TRISC14:1;
  unsigned TRISC15:1;
} TRISCBITS_REG;
#define TRISC_bits              (*((volatile TRISCBITS_REG *) 0x02CC))          // Polje bitova za pode?avanje ulazno izlaznih pinova porta C

typedef struct{
  unsigned :13;
  unsigned PORTC13:1;
  unsigned PORTC14:1;
  unsigned PORTC15:1;
} PORTCBITS_REG;
#define PORTC_bits              (*((volatile PORTCBITS_REG *) 0x02CE))          // Polje bitova za upis/?itanje sa pina porta C

typedef struct{
  unsigned :13;
  unsigned LATC13:1;
  unsigned LATC14:1;
  unsigned LATC15:1;
} LATCBITS_REG;
#define LATC_bits               (*((volatile LATCBITS_REG *) 0x02D0))           // Polje bitova za upis/?itanje sa LATCH registra porta C

// IO port D
#define TRISD_REG               (*((volatile int *) 0x02D2))                    // Port D registar za definisanje smera podataka (ulazni/izlazni pin)
#define PORTD_REG               (*((volatile int *) 0x02D4))                    // Port D registar za ?itanje podatka direktno sa pina
#define LATD_REG                (*((volatile int *) 0x02D6))                    // Port D registar za ?itanje podatka iz latch flip flopa

// IO port D - polja bitova
typedef struct{
  unsigned TRISD0:1;
  unsigned TRISD1:1;
  unsigned TRISD2:1;
  unsigned TRISD3:1;
} TRISDBITS_REG;
#define TRISD_bits              (*((volatile TRISDBITS_REG *) 0x02D2))          // Polje bitova za pode?avanje ulazno izlaznih pinova porta D

typedef struct{
  unsigned PORTD0:1;
  unsigned PORTD1:1;
  unsigned PORTD2:1;
  unsigned PORTD3:1;
} PORTDBITS_REG;
#define PORTD_bits              (*((volatile PORTDBITS_REG *) 0x02D4))          // Polje bitova za upis/?itanje sa pina porta D

typedef struct{
  unsigned LATD0:1;
  unsigned LATD1:1;
  unsigned LATD2:1;
  unsigned LATD3:1;
} LATDBITS_REG;
#define LATD_bits               (*((volatile LATDBITS_REG *) 0x02D6))           // Polje bitova za upis/?itanje sa LATCH registra porta D

// IO port E
#define TRISE_REG               (*((volatile int *) 0x02D8))                    // Port E registar za definisanje smera podataka (ulazni/izlazni pin)
#define PORTE_REG               (*((volatile int *) 0x02DA))                    // Port E registar za ?itanje podatka direktno sa pina
#define LATE_REG                (*((volatile int *) 0x02DC))                    // Port E registar za ?itanje podatka iz latch flip flopa

// IO port E - polja bitova
typedef struct{
  unsigned TRISE0:1;
  unsigned TRISE1:1;
  unsigned TRISE2:1;
  unsigned TRISE3:1;
  unsigned TRISE4:1;
  unsigned TRISE5:1;
  unsigned :2;
  unsigned TRISE8:1;
} TRISEBITS_REG;
#define TRISE_bits              (*((volatile TRISEBITS_REG *) 0x02D8))          // Polje bitova za pode?avanje ulazno izlaznih pinova porta E

typedef struct{
  unsigned PORTE0:1;
  unsigned PORTE1:1;
  unsigned PORTE2:1;
  unsigned PORTE3:1;
  unsigned PORTE4:1;
  unsigned PORTE5:1;
  unsigned :2;
  unsigned PORTE8:1;
} PORTEBITS_REG;
#define PORTE_bits              (*((volatile PORTEBITS_REG *) 0x02DA))          // Polje bitova za upis/?itanje sa pina porta E

typedef struct{
  unsigned LATE0:1;
  unsigned LATE1:1;
  unsigned LATE2:1;
  unsigned LATE3:1;
  unsigned LATE4:1;
  unsigned LATE5:1;
  unsigned :2;
  unsigned LATE8:1;
} LATEBITS_REG;
#define LATE_bits               (*((volatile LATEBITS_REG *) 0x02DC))           // Polje bitova za upis/?itanje sa LATCH registra porta E

// IO port F
#define TRISF_REG               (*((volatile int *) 0x02DE))                    // Port F registar za definisanje smera podataka (ulazni/izlazni pin)
#define PORTF_REG               (*((volatile int *) 0x02E0))                    // Port F registar za ?itanje podatka direktno sa pina
#define LATF_REG                (*((volatile int *) 0x02E2))                    // Port F registar za ?itanje podatka iz latch flip flopa

// IO port F - polja bitova
typedef struct{
  unsigned TRISF0:1;
  unsigned TRISF1:1;
  unsigned TRISF2:1;
  unsigned TRISF3:1;
  unsigned TRISF4:1;
  unsigned TRISF5:1;
  unsigned TRISF6:1;
} TRISFBITS_REG;
#define TRISF_bits              (*((volatile TRISFBITS_REG *) 0x02DE))          // Polje bitova za pode?avanje ulazno izlaznih pinova porta F

typedef struct{
  unsigned PORTF0:1;
  unsigned PORTF1:1;
  unsigned PORTF2:1;
  unsigned PORTF3:1;
  unsigned PORTF4:1;
  unsigned PORTF5:1;
  unsigned PORTF6:1;
} PORTFBITS_REG;
#define PORTF_bits              (*((volatile PORTFBITS_REG *) 0x02E0))          // Polje bitova za upis/?itanje sa pina porta F

typedef struct{
  unsigned LATF0:1;
  unsigned LATF1:1;
  unsigned LATF2:1;
  unsigned LATF3:1;
  unsigned LATF4:1;
  unsigned LATF5:1;
  unsigned LATF6:1;
} LATFBITS_REG;
#define LATF_bits               (*((volatile LATFBITS_REG *) 0x02E2))           // Polje bitova za upis/?itanje sa LATCH registra porta F


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

