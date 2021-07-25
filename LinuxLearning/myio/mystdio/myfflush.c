#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("before while");
	fflush(stdout);
	while(1);

	printf("after while");
	fflush(stdout);

	exit(0);
}
