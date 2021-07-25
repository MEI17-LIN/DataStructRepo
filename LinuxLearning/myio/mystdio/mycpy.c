#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE *src, *dest;
	int ch;

	if(argc < 3)
	{
		printf("Usage:...\n");
		exit(1);
	}


	src = fopen(argv[1],"r");
	if(src == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		fclose(src);
		perror("fopen()");
		exit(1);
	}



	while(1)
	{
		ch = fgetc(src);
		if(ch == EOF)
			break;
		fputc(ch, dest);
	}


	fclose(dest);
	fclose(src);

	exit(0);
}
