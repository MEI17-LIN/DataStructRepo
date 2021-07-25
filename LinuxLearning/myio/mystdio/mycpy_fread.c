#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv)
{
	FILE *src, *dest;
	char buff[BUFFERSIZE];
	int n = 0;


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



	while((n = fread(buff, 1, BUFFERSIZE, src)) > 0)
	{
		fwrite(buff, 1, BUFFERSIZE, dest);
	}


	fclose(dest);
	fclose(src);

	exit(0);
}
