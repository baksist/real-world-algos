#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node* nxt;
} node;

void push (node** head, int x);
void pop (node** head);
void print (node** head);
node* search (node** head, int x);
