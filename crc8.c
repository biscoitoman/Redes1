/* calculates 16-bit CRC of given data */
/* based on the polynomial  */
#include "headers.h"

// calcula o crc de 8 bits
// polinomio usado  
// X^8 + X^5 + X^4 + 1
unsigned char crc_8(mensagem_t msg)
{

	int i;
	char dividendo[66];
	//strcat(dividendo, &msg.tipo);
	//strcat(dividendo, &msg.tamanho);
	
	for(i = 0; i < 66; i++)
		dividendo[i] = 0;
	
	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tipo;
	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tamanho;
	printf("\na %lu a\n", strlen(dividendo));
	printf("\na %s a\n", dividendo);
	strcat(dividendo, msg.data);
	char zero = 0;
	strcat(dividendo, &zero);

	//for(i = 0; i < 66; i++)
		printf("%s", dividendo);

	char crc = 0;


	char *c;

	char *fim = &dividendo[65];
	*fim >>= 7;

	printf("\nc %d c \n", dividendo[65]);

	char *inicio = &dividendo[0];
		printf("\nb %d %d b \n", *inicio, *fim);
	while(inicio <= fim)
	{
		c = inicio;
		for(i = 0; i < 8; i++)
		{  
		 	if((crc ^ *c) & 1) 
		 		crc = (crc >> 1) ^ 0x8c;   
		 	else crc >>= 1;   
		 	*c >>= 1;  
		}
		inicio++;
	}  
	printf("\na %d, %c a\n", crc, crc);
	return (unsigned char)crc;
}