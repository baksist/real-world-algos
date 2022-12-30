#include <stdio.h>
#define QUEUE_SIZE 10

int q[QUEUE_SIZE];
int h = 0;
int t = 0;

void push(int x) {
	if (t == QUEUE_SIZE - 1)
		t = 0;
	q[t] = x;
	t++;
}

void pop() {
	if (t == QUEUE_SIZE - 1)
		h = 0;
	q[h] = 0;
	h++;
}

void print_q() {
	for(int i = 0; i < QUEUE_SIZE; i++)
		printf("%d ", i);
	printf("\n");
	for(int i = 0; i < QUEUE_SIZE; i++)
		printf("%d ", q[i]);
	printf("\n");
/*	for(int i = 0; i < QUEUE_SIZE; i++) {
		printf(" ");
		if (i == h)
			printf("h");
		if (i == t)
			printf("t");
	}
	printf("\n");*/
	printf("h = %d, t = %d\n", h, t);

}
int main(void) {
		push(1);
	print_q();
}
