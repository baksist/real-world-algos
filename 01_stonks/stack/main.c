#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

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
		for (int i = 0; i <= top; i++)
		{
			printf("%d\n", stack[i]);
		}
	}
}

int main()
{
	print_stack();
	get_top();

	pop(4);
	push(3);
	push(13);
	printf("%d\n", get_top());
	printf("\n\n");
	for(int i = 0; i < 10; i++)
		push(i);
	pop(top);
	print_stack();
	return 0;
}
