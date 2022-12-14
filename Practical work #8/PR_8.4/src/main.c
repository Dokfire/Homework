#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define n 100000



void * calc(void * arg){
	int t = *(int*) arg;
	int old_cancel_state;
	double i;
	double m = 1;
	double sum = 0;
	double x = -1;
	for (i = 0; i < n; i++){
		pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, &old_cancel_state);
		x *= -1;
		sum += x*(1/m);
		m += 2;
		printf("ТCurrent value: %f; Current iteration %.0f\n", sum*4, (i+1));
		pthread_setcancelstate(old_cancel_state, NULL);
	}
	printf("Final value: %f\n", sum*4);
}

int main(int argc, char **argv){
	if (argc == 1){
		printf("Missing argument!\n");
	}else{
		pthread_t thread;
		int a = atoi(argv[1]);
		if (pthread_create(&thread, NULL, &calc, &a) != 0) {
				fprintf(stderr, "Error (thread1)\n");
				return 1;
		}
		sleep(atoi(argv[1]));
		pthread_cancel(thread);
		void *result;
		if (!pthread_equal(pthread_self(), thread))
				pthread_join(thread, &result) ;
		if (result == PTHREAD_CANCELED){
			fprintf(stderr, "Canceled\n");
		}else fprintf(stderr, "Succesful exit\n");
	}
	return 0;
}
