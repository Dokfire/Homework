#ifndef FUNCTION_C
#define FUNCTION_C
#include <math.h>

//Print
void print(int *x, int size) {
	int i;
	printf("\n[");
	for(i = 0; i < size; i++){
		printf("%d\t", x[i]);
	}
	printf("]");
}


//Filling an array
void filling(int *x, int size) {
	int i;
	for(i = 0; i < size; i++){
		x[i] = random()%20000 - 10000;
	}
}


//Exercise 1
void z_1(int *x, int size) {
	int i, j;
	int quantity = 0;
	float summ = 0;
	for (i = 0; i < size; i++) {
		summ += x[i];
	}
	summ /= (float)size;
	for(j = 0; j < size; j++) {
		if ((float)x[j] > summ) {
			quantity++;
		}
	}
	printf("\n\nThe number of elements greater than the average value of the array elements: %d", quantity);
}


//Exercise 2
void z_2(int *x, int size) {
	int i, k = 0;
	int num;
	int summ = 0, tmp;
	for (i = 0; i < size; i++) {
		if (k == 0) {
			if (x[i] < 0) {
				num = i;
				k++;
			}
		}
	}
	for (i = num + 1; i < size; i++) {
		tmp = x[i];
		summ += abs(tmp);
	}
	printf("\n\nThe sum of the modules of the array elements located after the first negative element: %d", summ);
}


#endif
