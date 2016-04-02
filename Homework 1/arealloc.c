#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

void *arealloc(void *ptr,size_t nmemb, size_t size)
{
	if(nmemb  && size*nmemb/nmemb != size){	//Check for multiplication overlfow and make sure nmemb is greater than zero
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr,nmemb * size);
}

int main(void){	//Main for creation of executable
	int* arr = (int *) malloc(sizeof(int) * 10);
	arr = (int *)arealloc(arr,ULONG_MAX,ULONG_MAX);	//Since size_t is 64 bit we use ULONG_MAX to create the overlow
	if(arr==NULL)	//Test to check for the correct implementation of arealloc
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	return 0;
}
