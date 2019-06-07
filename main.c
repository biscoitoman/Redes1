#include "headers.h"

void ls(char *buffer, int pos)
{

}

void cd(char *buffer, DIR *mydir)
{
	int pos = 4;
	char diretorio[TAM_FILE];
	memset(diretorio, 0, sizeof(diretorio));
	int i = 0;
	char c;
	do
	{
		c = buffer[pos+i];
		diretorio[i] = c;
		i++;
	}while(c != '\0' || c != EOF || c != NULL || i < TAM_FILE);
	chdir(diretorio);
	mydir = opendir(".");
}

void envia_msg(char *buffer)
{
	mensagem_t msg;
	memset(msg, 0, sizeof(msg));
	msg.sequencia 	= 0;
	msg.tipo 		= 4;
	msg.tamanho 	= 63;
	msg.crc 		= crc(msg, 'w');
	msg.marcador	= 204;
	char c;
	int i = 0;
	int pos = 4;
	do
	{
		c = buffer[pos+i];
		msg.data[i] = c;
		i++;
	}while(c != '\0' || c != EOF || c != NULL || i < TAM_FILE);

	envio(msg);
}

void menu(void)
{
	int i;
	char buffer[TAM];
	char comando[4];
	char c;

	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;
	mydir = opendir(".");

	while(1)
	{
		memset(buffer, 0, sizeof(buffer));
		printf("\n$ ");
		fgets(buffer, TAM, stdin);
		i = 0;
		do
		{
			c = buffer[i];
			comando[i] = c;
			i++;
		}while(c != ' ' || c != EOF || c != NULL || i < 4);
		if(!strcmp(comando, "lsl"))
		{
			ls(buffer, i);
		}
		else if(!strcmp(comando, "lsr"))
		{

		}
		else if(!strcmp(comando, "cdl"))
			cd(buffer, mydir);
		else if(!strcmp(comando, "cdr"))
		{
			envia_msg(buffer);
		}
		else if(!strcmp(comando, "put"))
		{

		}
		else if(!strcmp(comando, "get"))
		{

		}
		else if(!strcmp(comando, "chat"))
		{

		}
		else if(!strcmp(comando, "quit"))
		{
			break;
		}
		else
		{
			puts("\ncomando invalido");
		}
	}
}

int main(void)
{
	menu();
	int i;

	//int socket = ConexaoRawSocket("enp0s31f6");
	//char buffer[TAM];
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
	//char c;
	mensagem_t msg_envio;
	msg_envio.sequencia 	= 2;
	msg_envio.tipo		= 2;
	msg_envio.tamanho	= 40;
	strcpy(msg_envio.data, "funcionaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	msg_envio.crc 		= '0';
	msg_envio.marcador	= ;

	msg_envio.crc 		= crc(msg_envio, 'w');
	printf("%d\n", msg_envio.crc);
	i = crc(msg_envio, 'r');

	//printf("%c %c %s\n", msg_envio.marcador, msg_envio.crc, msg_envio.data);
	printf("%d %d %d %s %d %c |%d|\n", msg_envio.sequencia, msg_envio.tipo, msg_envio.tamanho, msg_envio.data, msg_envio.crc, msg_envio.marcador, i);
	/*
	msg_t msg_recebe;

	while(1)
	{
		write(socket, &msg_envio, sizeof(msg_t));
		sleep(2);
		read(socket, &msg_recebe, sizeof(msg_t));
		if(msg_recebe.marcador == '2')
			break;
		//printf("%d %d %d %s %c %c\n", msg.sequencia, msg.tipo, msg.tamanho, msg.data, msg.crc, msg.marcador);
	}

	if(!crc_8(msg_recebe))
	*/
	/*
	write(socket, msg.sequencia, TAM);
	write(socket, msg.tipo, TAM);
	write(socket, msg.tamanho, TAM);
	write(socket, &msg.data, TAM);
	write(socket, &msg.crc, TAM);
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
