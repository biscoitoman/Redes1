#ifndef HEADERS_H
#define HEADERS_H

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/ethernet.h>
#include <linux/if_packet.h>
#include <linux/if.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define TAM 256

typedef struct mensagem
{
	unsigned char 	sequencia: 5,
					tipo: 5,
					tamanho: 6,
	 				crc,
	 				marcador;
	 char 			data[63];
}mensagem_t;

//unsigned char calc_crc(mensagem_t msg);
uint8_t gencrc(uint8_t *data, size_t len);
unsigned char crc_8(mensagem_t msg);
int crc_check(mensagem_t msg);


int ConexaoRawSocket(char *device);
int main(void);


#endif