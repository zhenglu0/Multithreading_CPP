#define __RINGBUFS_INIT_C
/****************************************************************************/
/*    FILE: ringBufS_init.c                                                 */
/*                                                                          */
/*    These files contain the attributes and methods needed to manage a     */
/*    ring buffer. It turns out that we do this so much, that it may be a   */
/*    good idea to just make a library that does this.                      */
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
#include  <string.h>
#include  "ringBufS.h"

/****************************************************************************/
/*                            CODE STARTS HERE                              */
/****************************************************************************/
void ringBufS_init (ringBufS *_this)
{
    /*****
      The following clears:
        -> buf
        -> head
        -> tail
        -> count
      and sets head = tail
    ***/
    memset (_this, 0, sizeof (*_this));
}




