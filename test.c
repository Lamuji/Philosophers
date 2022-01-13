#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // compile with -lpthread
#include <time.h>

void	*routine(void *arg)
{
	int index = *(int *)arg;
	printf("%d\n", primes[index]);
	free(arg);
}


int main (int argc,  char **argv)
{
	pthread_t th[10];

}
