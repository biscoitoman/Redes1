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
#include <dirent.h>
#include <stdint.h>


#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0x07
#define TAM 256
#define TAM_FILE 63

typedef struct mensagem
{
	unsigned char 	sequencia: 5,
					tipo: 5,
					tamanho: 6,
	 				crc,
	 				marcador;
	 char 			data[TAM_FILE];
}mensagem_t;

unsigned char crc (mensagem_t msg, char opt);
uint8_t crc_calc(uint8_t const message[], int nBytes);
int ConexaoRawSocket(char *device);
int main(void);


#endif