#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int matchForce(const char *str, const char *module)
// {
// 	int i = 0, j = 0;
// 	while(str[i] != '\0' && module[j] != '\0')
// 	{
// 		if(str[i] == module[j])
// 		{
// 			i++;
// 			j++;
// 		}
// 		else
// 		{
// 			i = i-j+1;
// 			j = 0;
// 		}
// 	}
// 	if(j == strlen(module))
// 	{
// 		return 0;
// 	}
// 	return -1;
// }


int kmpMatch(const void *mystr, const void *mymodule)
{
	const char * str = mystr, *module = mymodule;
	int next[strlen(module)];
	// calculat the next array
	int i = 1;
	int j = 0;
	next[0] = 0;	
	// 写法1
	for(i = 1; i < strlen(module); i++)
	{
		while(str[i] != str[j] && j > 0)
		{
			j = next[j-1];
		}
		if(str[i] == str[j])
			j++;
		next[i] = j;
		printf("next[%d] = %d\n", i, j);
	}

	//KMP match
	for(i = 0, j = 0 ; i < strlen(str); i++)
	{
		if(j == strlen(module) || strlen(str) - i < strlen(module) - j)
		{
			break;
		}

		if(str[i] == module[j])
		{
			printf("str[%d] (%c) == module[%d] (%c)\n", i, str[i], j, module[j]);
			j++;	
		}
		else
		{
			printf("str[%d] (%c) ！= module[%d] (%c)\n", i, str[i], j, module[j]);
			j = next[j];
			printf("j = next[j] (%d)\n", j);
		}
	}
	
	if(j == strlen(module))
		return i-1;
	return -1;

}


//#define MAXSIZE 1024



int main(int argc, char **argv)
{
	int index;
	if(argc < 3)
	{
		printf("The inputs are not enough!\n");
		exit(1);
	}

	printf("str:%s\nmodule:%s\n", argv[1], argv[2]);

	if((index = kmpMatch(argv[1],argv[2])) != -1)
	{
		printf("Matched from index [%d]\n", index);
		printf("Match succeeds!\n");
	}
	else
	{
		printf("Match fails!\n");
	}

	exit(0);
}
