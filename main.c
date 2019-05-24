#include "headers.h"

int main(void)
{
	int i;

	int socket = ConexaoRawSocket("enp0s31f6");
	char buffer[TAM];
	//for(i = 0; i < TAM; i++)
	//	buffer[i]='b';
/*
	struct sockaddr saddr;
	int saddr_len = sizeof(saddr);
*/
	//struct sockaddr_ll sadr_ll;

	//printf("%d ", arquivo);
	//printf("%ld\n", write(socket, buffer, TAM));
	//fflush(socket);
	char c;
	mensagem_t mensagem;
	mensagem.sequencia 	= 0;
	mensagem.tipo		= 0;
	mensagem.tamanho	= 40;
	strcpy(mensagem.data, "opora essa merda n funciona nunca vsf men");
	mensagem.crc 		= '0';
	mensagem.marcador	= '2';
	//for(i )
			printf("%c %c %s\n", mensagem.marcador, mensagem.crc, mensagem.data);
	printf("%d %d %d %s %c %c\n", mensagem.sequencia, mensagem.tipo, mensagem.tamanho, mensagem.data, mensagem.crc, mensagem.marcador);


	while(1)
	{
		write(socket, &mensagem, sizeof(mensagem_t));
		//read(socket, &mensagem, 1);
		//if(mensagem.marcador == '2')
		//	break;
		printf("%d %d %d %s %c %c\n", mensagem.sequencia, mensagem.tipo, mensagem.tamanho, mensagem.data, mensagem.crc, mensagem.marcador);

	}
	/*
	write(socket, mensagem.sequencia, TAM);
	write(socket, mensagem.tipo, TAM);
	write(socket, mensagem.tamanho, TAM);
	write(socket, &mensagem.data, TAM);
	write(socket, &mensagem.crc, TAM);
	*/
	/*char c;
	do{
		read(socket, &c, 1);
	}while(c != 'O');
	
	read(socket, buffer, TAM);
	//connect(socket, &saddr, (socklen_t)saddr_len);
	*/
	/*
	while(1)
	{
		send(socket, buffer, TAM, 0);

		for(i = 0; i < TAM; i++)
			printf("%c", buffer[i]);
		puts("");
	}*/
	/*
	for(i = 0; i < TAM; i++)
		printf("%c", buffer[i]);
	*/
	return 0;
}
