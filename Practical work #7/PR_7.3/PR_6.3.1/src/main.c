#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#define SEC 5



int main (int argc, char **argv) {
	int local = 0;
    fork();
    local++;
    fork();
    local++;
    printf("\n");
    printf("\nLocal = %d, Adress - %p | PID - %d | PPID - %d | ", local, &local, getpid(), getppid());
	return 0;
}
