#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 80
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

void unparenthesize(char* input)
{
	char c;
	int len = strlen(input) - 1;
	_Bool sym = true;
	_Bool same = true;
	for (int i = 0; i < len; i++)
	{
		c = input[i];
		if (is_stack_empty()) {
			push(c);
		}
		else
		{
			if (c == ']' || c == ')' || c == '}')
			{
				if (!is_stack_empty() && c - get_top() > 2)
					same = false;
				pop();
			}
			else
			{
				push(c);
			}
		}
	}
	if (!is_stack_empty())
		sym = false;
	printf("%d %d\n", sym, same);
}

int main()
{
	char input[INPUT_SIZE];
	fgets(input, INPUT_SIZE, stdin);
	unparenthesize(input);
	return 0;
}
