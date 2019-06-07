#include "headers.h"


uint8_t crc_calc(uint8_t const message[], int nBytes)
{
    uint8_t  remainder = 0;	


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

}   /* crc_calc() */

unsigned char crc (mensagem_t msg, char opt)
{
	if(opt == 'w')
	{
		unsigned char dividendo[65];
		memset(dividendo, 0, sizeof(dividendo)); 
		strcpy((char*)dividendo, msg.data);
		dividendo[63] = msg.tipo;
		dividendo[64] = msg.tamanho;
		return (unsigned char)crc_calc((const uint8_t *)dividendo, sizeof(dividendo));
	}
	else if(opt == 'r')
	{
		unsigned char dividendo[66];
		memset(dividendo, 0, sizeof(dividendo)); 
		strcpy((char*)dividendo, msg.data);
		dividendo[63] = msg.tipo;
		dividendo[64] = msg.tamanho;
		dividendo[65] = msg.crc;
		return (unsigned char)crc_calc((const uint8_t *)dividendo, sizeof(dividendo));
	}
	return '?';
}
