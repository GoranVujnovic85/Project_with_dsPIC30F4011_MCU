/* 
 * File:   Timer.h
 * Author: Lenovo
 *
 * Created on September 20, 2024, 12:16 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************************************************************************************************************************** 
                                                            TIMER/COUNTER PERIFERIJA
****************************************************************************************************************************************/ 

//------------------------------------------------------------------------------
// Makro definicije registarskih polja Timer/Counter periferija
//------------------------------------------------------------------------------

// TIMER1 (Tip A) registri
#define TMR1_REG                (*((volatile int *) 0x0100))        // Timer1 brojacki registar
#define PR1_REG                 (*((volatile int *) 0x0102))		// Timer1 period registar
#define T1CON_REG               (*((volatile int *) 0x0104))        // Timer1 konfiguracioni registar

// TIMER2/3 (Timer 2 - Tip B; Timer 3 - Tip C) registri
#define TMR2_REG                (*((volatile int *) 0x0106))		// Timer2 brojacki registar
#define TMR3HLD_REG             (*((volatile int *) 0x0108))        // Timer3 brojacki registar u rezimu 32-bitnog rada (MSB deo 32-bitne reci)
#define TMR3_REG                (*((volatile int *) 0x010A))		// Timer3 brojacki registar
#define PR2_REG                 (*((volatile int *) 0x010C))		// Timer2 period registar
#define PR3_REG                 (*((volatile int *) 0x010E))		// Timer3 period registar
#define T2CON_REG               (*((volatile int *) 0x0110))        // Timer2 konfiguracioni registar
#define T3CON_REG               (*((volatile int *) 0x0112))        // Timer3 konfiguracioni registar

// TIMER4/5 (Timer 4 - Tip B; Timer 5 - Tip C) registri
#define TMR4_REG                (*((volatile int *) 0x0114))		// Timer4 brojacki registar
#define TMR5HLD_REG             (*((volatile int *) 0x0116))        // Timer5 brojacki registar u rezimu 32-bitnog rada (MSB deo 32-bitne reci)
#define TMR5_REG                (*((volatile int *) 0x0118))		// Timer5 brojacki registar
#define PR4_REG                 (*((volatile int *) 0x011A))		// Timer4 period registar
#define PR5_REG                 (*((volatile int *) 0x011C))		// Timer5 period registar
#define T4CON_REG               (*((volatile int *) 0x011E))        // Timer4 konfiguracioni registar
#define T5CON_REG               (*((volatile int *) 0x0120))        // Timer5 konfiguracioni registar

//------------------------------------------------------------------------------
// Makro definicije bitova i grupa bitova Timer/Counter periferija
//------------------------------------------------------------------------------

// TIMER1 MASKE

// TMR1 registar - brojacki registar

// PR1 registar - period registar

// T1CON registar - konfiguracioni registar
#define T1CON_TCS               0x0002                              // TCS maska        
#define T1CON_TSYNC             0x0004                              // TSYNC maska
#define T1CON_PSC1              0x0000                              // TPSC maska - takt preskaler 1
#define T1CON_PSC8              0x0010                              // TPSC maska - takt preskaler 8
#define T1CON_PSC64             0x0020                              // TPSC maska - takt preskaler 64
#define T1CON_PSC256            0x0030                              // TPSC maska - takt preskaler 256
#define T1CON_TGATE             0x0040                              // TGATE maska
#define T1CON_TSIDL             0x2000                              // TSIDL maska
#define T1CON_TON               0x8000                              // TON maska   

// TIMER2/3 MASKE

// TMR2 registar - brojacki registar

// PR2 registar - period registar

// T2CON registar - konfiguracioni registar
#define T2CON_TCS               0x0002                              // TCS maska        
#define T2CON_T32             	0x0008                              // T32 maska
#define T2CON_PSC1              0x0000                              // TPSC maska - takt preskaler 1
#define T2CON_PSC8              0x0010                              // TPSC maska - takt preskaler 8
#define T2CON_PSC64             0x0020                              // TPSC maska - takt preskaler 64
#define T2CON_PSC256            0x0030                              // TPSC maska - takt preskaler 256
#define T2CON_TGATE             0x0040                              // TGATE maska
#define T2CON_TSIDL             0x2000                              // TSIDL maska
#define T2CON_TON               0x8000                              // TON maska   

// TMR3 registar - brojacki registar

// TMR3HLD registar - brojacki registar

// PR3 registar - period registar

// T3CON registar - konfiguracioni registar
#define T3CON_TCS               0x0002                              // TCS maska        
#define T3CON_PSC1              0x0000                              // TPSC maska - takt preskaler 1
#define T3CON_PSC8              0x0010                              // TPSC maska - takt preskaler 8
#define T3CON_PSC64             0x0020                              // TPSC maska - takt preskaler 64
#define T3CON_PSC256            0x0030                              // TPSC maska - takt preskaler 256
#define T3CON_TGATE             0x0040                              // TGATE maska
#define T3CON_TSIDL             0x2000                              // TSIDL maska
#define T3CON_TON               0x8000                              // TON maska   
  
// TIMER4/5 MASKE

// TMR4 registar - brojacki registar

// PR4 registar - period registar

// T4CON registar - konfiguracioni registar
#define T4CON_TCS               0x0002                              // TCS maska        
#define T4CON_T45             	0x0008                              // T45 maska
#define T4CON_PSC1              0x0000                              // TPSC maska - takt preskaler 1
#define T4CON_PSC8              0x0010                              // TPSC maska - takt preskaler 8
#define T4CON_PSC64             0x0020                              // TPSC maska - takt preskaler 64
#define T4CON_PSC256            0x0030                              // TPSC maska - takt preskaler 256
#define T4CON_TGATE             0x0040                              // TGATE maska
#define T4CON_TSIDL             0x2000                              // TSIDL maska
#define T4CON_TON               0x8000                              // TON maska   

// TMR5 registar - brojacki registar

// TMR5HLD registar - brojacki registar

// PR5 registar - period registar

// T5CON registar - konfiguracioni registar
#define T5CON_TCS               0x0002                              // TCS maska        
#define T5CON_PSC1              0x0000                              // TPSC maska - takt preskaler 1
#define T5CON_PSC8              0x0010                              // TPSC maska - takt preskaler 8
#define T5CON_PSC64             0x0020                              // TPSC maska - takt preskaler 64
#define T5CON_PSC256            0x0030                              // TPSC maska - takt preskaler 256
#define T5CON_TGATE             0x0040                              // TGATE maska
#define T5CON_TSIDL             0x2000                              // TSIDL maska
#define T5CON_TON               0x8000                              // TON maska   



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

