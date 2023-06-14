
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
		//read value of mails
		//increment
		//write mails
}

// void *routine2()
// {
// 	sleep(2);
// 	printf("Value of x: %d\n", x);
// }

int main(int argc, char **argv)
{
	int i;
	pthread_t th[4];
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0) //th + i and &th[i] is same
		{
			perror("Failed to create thread");
			return 1;
		}
		if (pthread_join(th[i], NULL) != 0)
			return 2;
	}
	if (pthread_join(t1, NULL) != 0)
	{
		return 3;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 4;
	}
	pthread_mutex_destroy(&mutex);
	printf("number of mails: %d\n", mails);
	return 0;
}
