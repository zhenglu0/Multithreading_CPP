#ifndef __MODULO_H
    #define  __MODULO_H
/****************************************************************************/
/*  FILE: modulo.h                                                          */
/*                                                                          */
/*  These files contain the attributes and methods for managing the         */
/*  modulus arithmetic                                                      */
/*                                                                          */
/*    BY: Ken Wada                                                          */
/*        Aurium Technologies Inc.                                          */
/*        Jul. 15, 2013                                                     */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
/*    THE COMPANY: Aurium Technologies Inc.                                 */
/*                                                                          */
/*    THIS FIRMWARE IS FREE TO USE AND TO MODIFY. IT IS PRESENTED HERE FOR  */
/*    DEMONSTRATION PURPOSES AS AN EXAMPLE ON HOW TO CODE FOR ANY DEEPLY    */
/*    EMBEDDED SYSTEM.                                                      */
/*                                                                          */
/*    AS A RESULT, THE COMPANY SHALL NOT BE HELD LIABLE FOR ANY DIRECT,     */
/*    INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING  */
/*    FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY USERS OF     */
/*    THE CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR      */
/*    PRODUCTS.                                                             */
/****************************************************************************/

  #ifdef __cplusplus
    extern "C"  {
  #endif
    unsigned int modulo_inc (const unsigned int value, const unsigned int modulus);
    unsigned int modulo_dec (const unsigned int value, const unsigned int modulus);
  #ifdef __cplusplus
    }
  #endif
#endif





