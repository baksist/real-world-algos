#include <stdio.h>
#include <stdlib.h>

int main() {
	int** arr;
	arr = (int**) malloc (sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		*(arr + i) = (int*) malloc (sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			arr[i][j] = i+j;
	return 0;
}
