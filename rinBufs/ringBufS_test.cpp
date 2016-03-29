/****************************************************************************/
/*  FILE: ringBufS_test.cpp                                                 */
/*                                                                          */
/*  These files contain the attributes and methods for managing the         */
/*  test method for the simple ring buffer                                  */
/*                                                                          */
/*    BY: Ken Wada                                                          */
/*        Aurium Technologies Inc.                                          */
/*        Jul. 16, 2013                                                     */
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
#include  <stdio.h>

#include  "ringBufS.h"

int main(int argc, char* argv[])
{
  int i;
  ringBufS my_ringBuffer;
  int my_status;
  ringBufS_init (&my_ringBuffer);

  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));

  puts ("\nThe following is the FIFO FULL status");
  for (i=0;i<RBUF_SIZE;i++)
  {
    ringBufS_put (&my_ringBuffer, (unsigned char)i);
    my_status = ringBufS_full(&my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%2d ", my_status);
  }

  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));
  puts ("\nThe following is the contents of the FIFO");
  for (i=0;i<RBUF_SIZE;i++)
  {
    int my_datum = ringBufS_get(&my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%02X ",my_datum);
  }
  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));

  putchar ('\n');
  return 0;
}






