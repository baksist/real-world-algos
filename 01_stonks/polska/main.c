#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}
char* filter(char* input)
{
	char* res = (char*) malloc (sizeof(char) * INPUT_SIZE);
	char c;
	int len = strlen(input);
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		c = input[i];
		if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '/' || c == '*')
		{
			res[pos] = c;
			pos++;
		}
	}
	res[pos] = '\0';
	res = realloc(res, sizeof(char) * pos);
	return res;
}
int eval (char* input)
{
	char c;
	int a, b, len;
	len = strlen(input) - 1;

	for (int i = 0; i < len; i++)
	{
		c = input[i];
		if (isdigit(c))
		{
			push(c - '0');
		}
		else
		{
			a = get_top();
			pop();
			b = get_top();
			pop();
			switch(c)
			{
				case '+':
					push(a + b);
					break;
				case '-':
					push(b - a);
					break;
				case '*':
					push(a * b);
					break;
				case '/':
					push(a / b);
					break;
				default:
					break;
			}
		}
	}	
	return get_top();
}
int main()
{
	char input[INPUT_SIZE];
	fgets(input, INPUT_SIZE, stdin);
	int res = eval(filter(input));
	printf("%d\n", res);
	return 0;
}
