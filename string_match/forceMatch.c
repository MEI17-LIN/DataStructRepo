#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct
// {
// 	char *data;
// 	int len;
// }String;


// String* initString()
// {
// 	String *s = malloc(sizeof(String));
// 	if(s == NULL)
// 		return NULL;
// 	s->len = 0;
// 	s->data = NULL;
// 	return s;
// }

// void stringAssign(String *s, char *data)
// {
    
	
// }


int matchForce(const char *str, const char *module)
{
	int i = 0, j = 0;
	while(str[i] != '\0' && module[j] != '\0')
	{
		if(str[i] == module[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j = 0;
		}
	}
	if(j == strlen(module))
	{
		return 0;
	}
	return -1;
}


//#define MAXSIZE 1024



int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("The inputs are not enough!\n");
		exit(1);
	}

	if(matchForce(argv[1],argv[2]) == 0)
	{
		printf("Match succeeds!\n");
	}
	else
	{
		printf("Match fails!\n");
	}

	exit(0);
}
