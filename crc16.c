/* calculates 16-bit CRC of given data */
/* based on the polynomial  X^8 + X^5 + X^4 + 1 */
#include "headers.h"

char crc_8(mensagem_t msg)
{
	char dividendo[66];
	strcat(dividendo, msg.tipo);
	strcat(dividendo, msg.tamanho);
	strcat(dividendo, msg.data);
	char zero = 0;
	strcat(dividendo, &zero);

	char crc = 0;

	int i;
	for(i = 0; i <; i++)
	{  
	 	if((crc ^ c) & 1) 
	 		crc=(crc>>1)^0x8c;   
	 	else crc>>=1;   
	 	c>>=1;  
	}  
	return crc;
}


unsigned int crc_8(unsigned int *start,unsigned int *end)
{ 
	unsigned int crc=0,c; 
	int i; 
	while (start<=end) 
	{  
		c=*start;  
		for(i=0;i<8;i++) 
		{  
		 	if((crc ^ c) & 1) 
		 		crc=(crc>>1)^0x8c;   
		 	else crc>>=1;   
		 	c>>=1;  
		}  
		start++; 
	} 
	return(crc);
}