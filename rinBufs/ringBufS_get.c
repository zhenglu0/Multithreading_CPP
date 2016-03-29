#define __RINGBUFS_GET_C
/****************************************************************************/
/*    FILE: ringBufS_get.c                                                  */
/*                                                                          */
/*    These files contain the attributes and methods needed to manage a     */
/*    256-byte ring buffer. It turns out that we do this so much, that it   */
/*    may be a good idea to just make a library that does this.             */
/*                                                                          */
/*      BY:   Ken Wada                                                      */
/*            Aurium Technologies Inc.                                      */
/*            15-July-2013                                                  */
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
#include  "modulo.h"
#include  "ringBufS.h"

/****************************************************************************/
/*                            CODE STARTS HERE                              */
/****************************************************************************/
int ringBufS_get (ringBufS *_this)
{
    int c;
    if (_this->count>0)
    {
      c           = _this->buf[_this->tail];
      _this->tail = modulo_inc (_this->tail, RBUF_SIZE);
      --_this->count;
    }
    else
    {
      c = -1;
    }
    return (c);
}







