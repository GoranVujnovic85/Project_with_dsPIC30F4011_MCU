/* 
 * File:   MATH.h
 * Author: Lenovo
 *
 * Created on September 19, 2024, 10:25 AM
 */

#ifndef MATH_H
#define	MATH_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************************************************************************************************************************** 
                                                            BITWISE MAKROI 
****************************************************************************************************************************************/ 

//------------------------------------------------------------------------------
// Makro definicije za operisanje sa bitovima
//------------------------------------------------------------------------------

/* Pristupni makroi za celokupne registre periferija */
#define setReg16(RegName, val)                                                  (RegName = (int)(val))
#define clrReg16(RegName)                                                       (RegName = 0)
#define getReg16(RegName)                                                       (RegName)

/* Pristupni makroi za pojedine bitove registara periferija */
#define testReg16Bits(RegName, GetMask)                                         (RegName & (GetMask))
#define clrReg16Bits(RegName, ClrMask)                                          (RegName &= ~(int)(ClrMask))
#define setReg16Bits(RegName, SetMask)                                          (RegName |= (int)(SetMask))
#define invertReg16Bits(RegName, InvMask)                                       (RegName ^= (int)(InvMask))
#define clrSetReg16Bits(RegName, ClrMask, SetMask)                              (RegName = (RegName & (~(int)(ClrMask))) | (int)(SetMask))
#define seqClrSetReg16Bits(RegName, BitsMask, BitsVal)                          ( RegName &= ~(~(int)(BitsVal) & (int)(BitsMask)),\RegName |= (int)(BitsVal) & (int)(BitsMask) )
#define seqSetClrReg16Bits(RegName, BitsMask, BitsVal)                          ( RegName |= (int)(BitsVal) & (int)(BitsMask),\RegName &= ~(~(int)(BitsVal) & (int)(BitsMask)) )
#define seqResetSetReg16Bits(RegName, BitsMask, BitsVal)                        ( RegName &= ~(int)(BitsMask),\RegName |= (int)(BitsVal) & (int)(BitsMask) )
#define clrReg16BitsByOne(RegName, ClrMask, BitsMask)                           (RegName &= (int)(ClrMask) & (int)(BitsMask))

#ifdef	__cplusplus
}
#endif

#endif	/* MATH_H */

