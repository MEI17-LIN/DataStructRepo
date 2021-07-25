#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *line_buff = NULL;
	size_t line_size = 0;


	if(argc < 2)
	{
		fprintf(stderr, "Usage:...");
		exit(1);
	}

	fp = fopen(argv[1], "r");
	
	if(fp == NULL)
	{
		perror("fopen() failed:");
		exit(1);
	}

	while(1)
	{
		if(getline(&line_buff,&line_size,fp) < 0)
		{
			break;
		}
		printf("%ld, %ld\n",strlen(line_buff), line_size);
	}
	
	free(line_buff); 
	
	fclose(fp);

	exit(0);
}
