#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

//tamanho máximo de nome de arquivo/diretório
#define TAM 63

int main(/*int argc, char* argv[]*/void){
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;
	mydir = opendir(".");
	
	while(1){
		
		int i;
		
		getchar();	// para não pegar o espaço

		// i = -1;
		// do{
		// 	i++;
		// 	diretorio[i] = getchar();
		// }while(diretorio[i] != '\n');
		// diretorio[i] = '\0';
		//coloca opção aqui
		
		//ls
		if(!strcmp("ls", funcao))
		{
			DIR *cur_dir = mydir;
			mydir = opendir(diretorio);
			while((myfile = readdir(mydir)) != NULL)
			{
				stat(myfile->d_name, &mystat);    
				printf("%ld",mystat.st_size);
				printf(" %s\n", myfile->d_name);
			}
			mydir = cur_dir;
		}
		
		//cd
		else if(!strcmp("cd", funcao))
		{
			chdir(diretorio);
			mydir = opendir(".");
		}
	}
    
}
