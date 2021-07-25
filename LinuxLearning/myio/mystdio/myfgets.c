#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	char *p = NULL;
	int cnt = 0;

	if(argc < 1)
	{
		fprintf(stderr, "Usage:...\n");
		exit(1);
	}

	p = malloc(5);



	fgets(p, 5, stdin);
	
	
	printf("%s", p);

	exit(0);
}
