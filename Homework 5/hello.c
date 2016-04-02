#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *thread(void *vargp);

int main(int argc, char* argv[])
{
	int num = atoi(argv[1]); //Get number of threads we want
	pthread_t *tid = malloc(sizeof(pthread_t)*num); //Create that many tids by allocating that much space
	for(int i = 0; i < num; i++)
	{
		pthread_create(&tid[i], NULL, thread, NULL); //Create that many number of threads
	}
	for (int j = 0; j < num; j++)
	{
		pthread_join(tid[j], NULL); //Join all the threads back
	}
	free(tid); //Free the allocated space for the tid's
	exit(0);
}

void *thread(void *vargp)
{
	printf("Hello, world!\n"); 
	return NULL;
}
