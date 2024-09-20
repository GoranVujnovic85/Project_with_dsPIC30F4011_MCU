/* 
 * File:   UART.h
 * Author: Lenovo
 *
 * Created on September 19, 2024, 10:18 AM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************************************************************************************************************************** 
                                                       UART PERIFERIJA 
****************************************************************************************************************************************/ 

//------------------------------------------------------------------------------
// Makro definicije registarskih polja UART periferije
//------------------------------------------------------------------------------
#define U1MODE_REG              (*((volatile int *) 0x020C))       	            // Konfiguracioni registar UART1 jedinice
#define U1STA_REG              	(*((volatile int *) 0x020E))       	            // Statusno-kontrolni registar UART1 jedinice
#define U1TX_REG              	(*((volatile int *) 0x0210))       	            // UART1 PISO registar
#define U1RX_REG              	(*((volatile int *) 0x0212))       	            // UART1 SIPO jedinice
#define U1BRG_REG              	(*((volatile int *) 0x0214))       	            // Registar za definisanje Baud Rate UART1 jedinice

#define U2MODE_REG              (*((volatile int *) 0x0216))       	            // Konfiguracioni registar UART2 jedinice
#define U2STA_REG              	(*((volatile int *) 0x0218))       	            // Statusno-kontrolni registar UART2 jedinice
#define U2TX_REG              	(*((volatile int *) 0x021A))       	            // UART2 PISO registar
#define U2RX_REG              	(*((volatile int *) 0x021C))       	            // UART2 SIPO jedinice
#define U2BRG_REG              	(*((volatile int *) 0x021E))       	            // Registar za definisanje Baud Rate UART2 jedinice

// USTA - polja bitova
typedef struct{
  unsigned URXDA:1;
  unsigned OERR:1;
  unsigned FERR:1;
  unsigned PERR:1;
  unsigned RIDLE:1;
  unsigned :3;
  unsigned TRMT:1;
  unsigned UTXBF:1;  
} USTABITS_REG;
#define U1STA_bits             (*((volatile USTABITS_REG *) 0x020E))          	// Polje bitova za status UART1 jedinice
#define U2STA_bits             (*((volatile USTABITS_REG *) 0x0218))          	// Polje bitova za status UART2 jedinice

// UTX - unija polja bitova
typedef union{
  unsigned int UTX9;
  struct {
	unsigned UTX:8;
	unsigned UTX8:1;	    
  };
} UTXBITS_REG;
#define U1TX_bits             	(*((volatile UTXBITS_REG *) 0x0210))          		
#define U2TX_bits             	(*((volatile UTXBITS_REG *) 0x021A))  

// URX - unija polja bitova
typedef union{
  unsigned int URX9;
  struct {
	unsigned URX:8;
	unsigned URX8:1;	    
  };
} URXBITS_REG;
#define U1RX_bits             	(*((volatile URXBITS_REG *) 0x0212))          		
#define U2RX_bits             	(*((volatile URXBITS_REG *) 0x021C))          		

//------------------------------------------------------------------------------
// Makro definicije bitova i grupa bitova UART periferije
//------------------------------------------------------------------------------

// U1MODE registar - Konfiguracioni registar UART1 jedinice
#define UMODE_STSEL             0x0001                                          // STSEL maska

#define UMODE_PDSEL0        	0x0000                                          // PDSEL maska - 8-bitni prenos bez parity bita
#define UMODE_PDSEL1        	0x0002                                          // PDSEL maska - 8-bitni prenos sa even parity logikom
#define UMODE_PDSEL2        	0x0004                                          // PDSEL maska - 8-bitni prenos sa odd parity logikom
#define UMODE_PDSEL3        	0x0006                                          // PDSEL maska - 9-bitni prenos bez parity bita

#define UMODE_ABAUD             0x0020                                          // ABAUD maska
#define UMODE_LPBACK        	0x0040                                          // LPBACK maska
#define UMODE_WAKE        		0x0080                                          // WAKE maska
#define UMODE_ALTIO             0x0400                                          // ALTIO maska
#define UMODE_USIDL             0x2000                                          // USIDL maska
#define UMODE_UARTEN        	0x8000                                          // UARTEN maska

// U1STA registar - Statusno-kontrolni registar UART1 jedinice
#define USTA_ADDEN        		0x0020                                          // ADDEN maska

#define USTA_URXISEL0        	0x0000                                          // URXISEL maska - statusni flag za prekid nakon svakog prijema
#define USTA_URXISEL1        	0x0040                                          // URXISEL maska - statusni flag za prekid nakon svakog prijema
#define USTA_URXISEL2        	0x0080                                          // URXISEL maska - statusni flag za prekid nakon 3/4 punog prijemnog bafera
#define USTA_URXISEL3        	0x00C0                                          // URXISEL maska - statusni flag za prekid nakon punog prijemnog bafera

#define USTA_UTXEN        		0x0400                                          // UTXEN maska
#define USTA_UTXBRK             0x0800                                          // UTXBRK maska
#define USTA_UTXISEL        	0x8000                                          // UTXISEL maska



#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

