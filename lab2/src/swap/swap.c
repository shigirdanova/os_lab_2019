#include "swap.h"
#include <stdlib.h>

void Swap(char *left, char *right)
{
	char* storage = (char*)malloc(5);
	*storage = *left;
	*left = *right;
	*right = *storage;	
	free(storage);
}
