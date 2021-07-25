#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv)
{
	FILE *src, *dest;
	char buff[BUFFERSIZE];

	if(argc < 3)
	{
		printf("Usage:...\n");
		exit(1);
	}


	src = fopen(argv[1],"r");
	if(src == NULL)
	{
		perror("0fopen()");
		exit(1);
	}

	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		fclose(src);
		perror("1fopen()");
		exit(1);
	}



	while(fgets(buff, BUFFERSIZE, src) != NULL)
	{
		fputs(buff, dest);
	}


	fclose(dest);
	fclose(src);

	exit(0);
}
