#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100000000

typedef struct stack stack;

struct stack {
	int top;
	int* data;
};

stack* new_stack(){
	stack* out = malloc(sizeof(stack));
	out->top = -1;
	out->data = NULL;
	return out;
}

void push(stack* s, int x) {
	if (s->top == MAX_STACK_SIZE)
		printf("Stack overflow\n");
	else {
		s->top++;
		s->data = realloc(s->data, sizeof(int) * (s->top + 1));
		s->data[s->top] = x;
	}
}

void pop(stack* s) {
	if (s->top < 0) {
		printf("Stack underflow\n");
	}
	else {
		s->data = realloc(s->data, sizeof(int) * s->top);
	}
	s->top--;
}

int peek(stack* s) {
	if (s->top < 0)
		printf("Stack is empty\n");
	else
		return s->data[s->top];
}

int main() {
	stack* kek;
	kek = new_stack();
	push(kek, 3);
	printf("%d\n", peek(kek));
//	pop(kek);
	return 0;
}
