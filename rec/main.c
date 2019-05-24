#include "headers.h"

int main(void)
{
	int i;

	int socket = ConexaoRawSocket("lo");
	char buffer[TAM];
	for(i = 0; i < TAM; i++)
		buffer[i]='b';
/*
	struct sockaddr saddr;
	int saddr_len = sizeof(saddr);
*/
	//struct sockaddr_ll sadr_ll;

	//printf("%d ", arquivo);
	while(1)	
		printf("%ld\n", write(socket, buffer, TAM));
	//printf("%ld\n", read(socket, buffer, TAM));
	//connect(socket, &saddr, (socklen_t)saddr_len);
	/*while(1)
	{
		send(socket, buffer, TAM, 0);

		for(i = 0; i < TAM; i++)
			printf("%c", buffer[i]);
		puts("");
	}*/
	return 0;
}
