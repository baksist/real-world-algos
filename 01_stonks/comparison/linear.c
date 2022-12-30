#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define STACK_SIZE 500000
#define STOCKS_SIZE 500000

int seed = 1;//time(NULL);
int* generate_stocks();
int* stack_stock_span(int* quotes);

int stack[STACK_SIZE];
int top = -1;
void pop();
void push(int x);
_Bool is_stack_empty();
int get_top();
void print_stack();

int main()
{
	int* stonks = generate_stocks();
	printf("\n");
	int* spans = stack_stock_span(stonks);
	free(stonks);
	free(spans);
	return 0;
}

int* generate_stocks()
{
	int* quotes = (int*) malloc (sizeof(int) * STOCKS_SIZE);
	srand(seed);
	for (int i = 0; i < STOCKS_SIZE; i++)
	{
		quotes[i] = rand() % 100 + 1;
//		printf("%d\n", quotes[i]);
	}
	return quotes;
}

int* stack_stock_span(int* quotes)
{
	int* spans = (int*) malloc (sizeof(int) * STOCKS_SIZE);
	spans[0] = 1;
	push(0);
	for(int i = 0; i < STOCKS_SIZE; i++)
	{
		while (!is_stack_empty() && quotes[get_top()] <= quotes[i])
		{
			pop();
		}
		if (is_stack_empty())
			spans[i] = i + 1;
		else
			spans[i] = i - get_top();
		push(i);
//		printf("%d\n", spans[i]);
	}
	return spans;
}

void pop()
{
	if (top <= -1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		top--;
	}
}

void push(int x)
{
	if (top >= STACK_SIZE - 1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top] = x;
	}
}


_Bool is_stack_empty()
{
	if (top <= -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int get_top()
{
	if (is_stack_empty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return stack[top];
	}
}

void print_stack()
{
	if (is_stack_empty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			printf("%d\n", stack[i]);
		}
	}
}


