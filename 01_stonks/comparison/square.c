#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define STOCKS_SIZE 500000

int seed = 1;

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

int* simple_stock_span(int* quotes)
{
	int k;
	_Bool span_end;
	int* spans = (int*) malloc (sizeof(int) * STOCKS_SIZE);
	for (int i = 0; i < STOCKS_SIZE; i++)
	{
		k = 1;
		span_end = false;
		while (i - k >= 0 && !span_end)
		{
			if (quotes[i - k] <= quotes[i])
			{
				k++;
			}
			else
			{
				span_end = true;
			}
		}
		spans[i] = k;
//		printf("%d\n", spans[i]);
	}
	return spans;
}

int main()
{
	int* stonks = generate_stocks();
	int* spanz = simple_stock_span(stonks);
	free(stonks);
	free(spanz);
	return 0;
}
