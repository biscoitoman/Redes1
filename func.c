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
	
	memset(dividendo, 0, sizeof(dividendo));
	
	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tipo;
	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tamanho;
	printf("\na %lu a\n", strlen(dividendo));
	strcat(dividendo, msg.data);
	char zero = 0;
	strcat(dividendo, &zero);
/*
	for(i = 0; i < 66; i++)
		printf("%c", dividendo[i]);

	//printf("\nn %c n\n", dividendo[0]);
	char crc = 0;


	char *c;

	char *fim = &dividendo[65];
	//fim >>= 7;

	printf("\nc %d c \n", dividendo[65]);

	char *inicio = &dividendo[0];
		printf("\nb %d %d b \n", *inicio, *fim);
	while(inicio <= fim)
	{
		c = inicio;
		for(i = 0; i < 8; i++)
		{  
		 	if((crc ^ *c) & 1) 
		 		crc = (crc >> 1) ^ 0x31;   
		 	else crc >>= 1;   
		 	*c >>= 1;  
		}
		inicio++;
	}  */
	printf("\n %lu %c asdf\n", sizeof(dividendo), dividendo[2]);
	return gencrc((unsigned char*)dividendo, sizeof(dividendo));
	//printf("\na %d, %c a\n", crc, crc);
	//return (unsigned char)crc;
}

uint8_t gencrc(uint8_t *data, size_t len)
{
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ 0x31);
            else
                crc <<= 1;
        }
    }
    return crc;
}

int crc_check(mensagem_t msg)
{
	int i;
	char dividendo[66];
	//char divisor[66];
	//strcat(dividendo, &msg.tipo);
	//strcat(dividendo, &msg.tamanho);
	
	memset(dividendo, 0, sizeof(dividendo));
	//memset(divisor, 0, sizeof(divisor));

	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tipo;
	*dividendo = *dividendo << 5;
	*dividendo = *dividendo + msg.tamanho;
	printf("\na %lu a\n", strlen(dividendo));
	strcat(dividendo, msg.data);
	dividendo[65] = msg.crc;
/*
	int crc = 0;


	*divisor |= 0x31;
	//divisor <<= (sizeof(divisor)-1)*8;

	for(i = 0; i < (66 - 1)*8; i++)
	{
		*dividendo ^= *divisor;
		*divisor >>= 1;
	}
	printf("\n| %s\n", dividendo);*/
	//crc = strcmp(dividendo, "");
	int a = gencrc((unsigned char *)dividendo, sizeof(dividendo));
	printf("\n|%d|\n", a);
	if(a == 0)
		return 0;
	else return 1;
}