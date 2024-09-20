/* 
 * File:   Interrupts.h
 * Author: Lenovo
 *
 * Created on September 19, 2024, 10:32 AM
 */

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#ifdef	__cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// Makro definicije registarskih polja periferije za rad sa prekidnim rutinama
//------------------------------------------------------------------------------

#define INTCON1_REG             (*((volatile int *) 0x0080))                    // Konfiguracioni registar za prekidne rutine - 1
#define INTCON2_REG             (*((volatile int *) 0x0082))                    // Konfiguracioni registar za prekidne rutine - 2
#define IFS0_REG                (*((volatile int *) 0x0084))                    // Statusni registar za prekidne rutine - 0
#define IFS1_REG                (*((volatile int *) 0x0086))                    // Statusni registar za prekidne rutine - 1
#define IFS2_REG                (*((volatile int *) 0x0088))                    // Statusni registar za prekidne rutine - 2
#define IEC0_REG                (*((volatile int *) 0x008C))                    // Registar za dozvolu prekidnih rutina - 0
#define IEC1_REG                (*((volatile int *) 0x008E))                    // Registar za dozvolu prekidnih rutina - 1
#define IEC2_REG                (*((volatile int *) 0x0090))                    // Registar za dozvolu prekidnih rutina - 2
#define IPC0_REG                (*((volatile int *) 0x0094))                    // Registar za definisanje prioriteta prekidnih rutina - 0
#define IPC1_REG                (*((volatile int *) 0x0096))                    // Registar za definisanje prioriteta prekidnih rutina - 1
#define IPC2_REG                (*((volatile int *) 0x0098))                    // Registar za definisanje prioriteta prekidnih rutina - 2
#define IPC3_REG                (*((volatile int *) 0x009A))                    // Registar za definisanje prioriteta prekidnih rutina - 3
#define IPC4_REG                (*((volatile int *) 0x009C))                    // Registar za definisanje prioriteta prekidnih rutina - 4
#define IPC5_REG                (*((volatile int *) 0x009E))                    // Registar za definisanje prioriteta prekidnih rutina - 5
#define IPC6_REG                (*((volatile int *) 0x00A0))                    // Registar za definisanje prioriteta prekidnih rutina - 6
#define IPC9_REG                (*((volatile int *) 0x00A6))                    // Registar za definisanje prioriteta prekidnih rutina - 9
#define IPC10_REG               (*((volatile int *) 0x00A8))                    // Registar za definisanje prioriteta prekidnih rutina - 10

// IFS0 - polja bitova
typedef struct{
  unsigned INT0IF:1;
  unsigned IC1IF:1;
  unsigned OC1IF:1;
  unsigned T1IF:1;
  unsigned IC2IF:1;
  unsigned OC2IF:1;
  unsigned T2IF:1;
  unsigned T3IF:1;
  unsigned SPI1IF:1;
  unsigned U1RXIF:1;
  unsigned U1TXIF:1;
  unsigned ADIF:1;
  unsigned NVMIF:1;
  unsigned SI2CIF:1;
  unsigned MI2CIF:1;
  unsigned CNIF:1;  
} IFS0BITS_REG;
#define IFS0_bits              (*((volatile IFS0BITS_REG *) 0x0084))          	// Polje bitova za rukovanje statusima prekidnih periferija - 0

// IFS1 - polja bitova
typedef struct{
  unsigned INT1IF:1;
  unsigned IC7IF:1;
  unsigned IC8IF:1;
  unsigned OC3IF:1;
  unsigned OC4IF:1;
  unsigned T4IF:1;
  unsigned T5IF:1;
  unsigned INT2IF:1;
  unsigned U2RXIF:1;
  unsigned U2TXIF:1;
  unsigned :1;  
  unsigned C1IF:1;
} IFS1BITS_REG;
#define IFS1_bits              (*((volatile IFS1BITS_REG *) 0x0086))          	// Polje bitova za rukovanje statusima prekidnih periferija - 1

// IFS2 - polja bitova
typedef struct{
  unsigned :7;
  unsigned PWMIF:1;
  unsigned QEIIF:1;
  unsigned :2;
  unsigned FLTAIF:1;
} IFS2BITS_REG;
#define IFS2_bits              (*((volatile IFS2BITS_REG *) 0x0088))          	// Polje bitova za rukovanje statusima prekidnih periferija - 2

// IEC0 - polja bitova
typedef struct{
  unsigned INT0IE:1;
  unsigned IC1IE:1;
  unsigned OC1IE:1;
  unsigned T1IE:1;
  unsigned IC2IE:1;
  unsigned OC2IE:1;
  unsigned T2IE:1;
  unsigned T3IE:1;
  unsigned SPI1IE:1;
  unsigned U1RXIE:1;
  unsigned U1TXIE:1;
  unsigned ADIE:1;
  unsigned NVMIE:1;
  unsigned SI2CIE:1;
  unsigned MI2CIE:1;
  unsigned CNIE:1;  
} IEC0BITS_REG;
#define IEC0_bits              (*((volatile IEC0BITS_REG *) 0x008C))          	// Polje bitova za rukovanje dozvolama prekidnih periferija - 0

// IEC1 - polja bitova
typedef struct{
  unsigned INT1IE:1;
  unsigned IC7IE:1;
  unsigned IC8IE:1;
  unsigned OC3IE:1;
  unsigned OC4IE:1;
  unsigned T4IE:1;
  unsigned T5IE:1;
  unsigned INT2IE:1;
  unsigned U2RXIE:1;
  unsigned U2TXIE:1;
  unsigned :1;  
  unsigned C1IE:1;
} IEC1BITS_REG;
#define IEC1_bits              (*((volatile IEC1BITS_REG *) 0x008E))          	// Polje bitova za rukovanje dozvolama prekidnih periferija - 1

// IEC2 - polja bitova
typedef struct{
  unsigned :7;
  unsigned PWMIE:1;
  unsigned QEIIE:1;
  unsigned :2;
  unsigned FLTAIE:1;
} IEC2BITS_REG;
#define IEC2_bits              (*((volatile IEC2BITS_REG *) 0x0090))          	// Polje bitova za rukovanje dozvolama prekidnih periferija - 2

// IPC0 - polja bitova
typedef struct{
  unsigned INT0IP:3;
  unsigned :1;
  unsigned IC1IP:3;
  unsigned :1;
  unsigned OC1IP:3;
  unsigned :1;
  unsigned T1IP:3;
  unsigned :1;
} IPC0BITS_REG;
#define IPC0_bits              (*((volatile IPC0BITS_REG *) 0x0094))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 0

// IPC1 - polja bitova
typedef struct{
  unsigned IC2IP:3;
  unsigned :1;
  unsigned OC2IP:3;
  unsigned :1;
  unsigned T2IP:3;
  unsigned :1;
  unsigned T3IP:3;
  unsigned :1;
} IPC1BITS_REG;
#define IPC1_bits              (*((volatile IPC1BITS_REG *) 0x0096))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 1

// IPC2 - polja bitova
typedef struct{
  unsigned SPI1IP:3;
  unsigned :1;
  unsigned U1RXIP:3;
  unsigned :1;
  unsigned U1TXIP:3;
  unsigned :1;
  unsigned ADIP:3;
  unsigned :1;
} IPC2BITS_REG;
#define IPC2_bits              (*((volatile IPC2BITS_REG *) 0x0098))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 2

// IPC3 - polja bitova
typedef struct{
  unsigned NVMIP:3;
  unsigned :1;
  unsigned SI2CIP:3;
  unsigned :1;
  unsigned MI2CIP:3;
  unsigned :1;
  unsigned CNIP:3;
  unsigned :1;
} IPC3BITS_REG;
#define IPC3_bits              (*((volatile IPC3BITS_REG *) 0x009A))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 3

// IPC4 - polja bitova
typedef struct{
  unsigned INT1IP:3;
  unsigned :1;
  unsigned IC7IP:3;
  unsigned :1;
  unsigned IC8IP:3;
  unsigned :1;
  unsigned OC3IP:3;
  unsigned :1;
} IPC4BITS_REG;
#define IPC4_bits              (*((volatile IPC4BITS_REG *) 0x009C))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 4

// IPC5 - polja bitova
typedef struct{
  unsigned OC4IP:3;
  unsigned :1;
  unsigned T4IP:3;
  unsigned :1;
  unsigned T5IP:3;
  unsigned :1;
  unsigned INT2IP:3;
  unsigned :1;
} IPC5BITS_REG;
#define IPC5_bits              (*((volatile IPC5BITS_REG *) 0x009E))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 5

// IPC6 - polja bitova
typedef struct{
  unsigned U2RXIP:3;
  unsigned :1;
  unsigned U2TXIP:3;
  unsigned :5;
  unsigned C1IP:3;
  unsigned :1;
} IPC6BITS_REG;
#define IPC6_bits              (*((volatile IPC6BITS_REG *) 0x00A0))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 6

// IPC9 - polja bitova
typedef struct{
  unsigned :12;
  unsigned PWMIP:3;
  unsigned :1;
} IPC9BITS_REG;
#define IPC9_bits              (*((volatile IPC9BITS_REG *) 0x00A6))          	// Polje bitova za rukovanje prioritetima prekidnih periferija - 9

// IPC10 - polja bitova
typedef struct{
  unsigned QEIIP:3;
  unsigned :9;
  unsigned FLTAIP:3;  
  unsigned :1;
} IPC10BITS_REG;
#define IPC10_bits              (*((volatile IPC10BITS_REG *) 0x00A8))          // Polje bitova za rukovanje prioritetima prekidnih periferija - 10


#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTS_H */

