#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef uint8_t crc;

#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0x07

crc crcSlow(uint8_t const message[], int nBytes)
{
    crc  remainder = 0;	


    /*
     * Perform modulo-2 division, a byte at a time.
     */
    for (int byte = 0; byte < nBytes; ++byte)
    {
        /*
         * Bring the next byte into the remainder.
         */
        remainder ^= (message[byte] << (WIDTH - 8));

        /*
         * Perform modulo-2 division, a bit at a time.
         */
        for (uint8_t bit = 8; bit > 0; --bit)
        {
            /*
             * Try to divide the current data bit.
             */
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }

    /*
     * The final remainder is the CRC result.
     */
    return (remainder);

}   /* crcSlow() */

int main (int argc, char *argv[]){
	unsigned char a[5] = "fodas";
	unsigned char c[6];
	memset(c,0,sizeof(c)); 
	unsigned char b = (unsigned char)crcSlow((const uint8_t *)a, sizeof(a));
	for (int i =0 ; i<5;i++)
		c[i] = a[i];
	c[5] = b ;
	printf("%d\n",b);
	printf("%s\n",c);
	b = (unsigned char)crcSlow((const uint8_t *)c, sizeof(c));
	printf("%d\n",b);	
	
}
