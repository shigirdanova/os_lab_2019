#include "static_rev.h"
#include "string.h"
#include <stdio.h>


extern void RevertString(char *str)
{	
	int i;		
	for (i=0; i < strlen(str) / 2; i++)
	{	
		char tmp = ' ';
		tmp = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = str[i];
		str[i] = tmp;
	}
}

