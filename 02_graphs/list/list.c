#include "list.h"

void push (node** head, int x) {
	node** cur = head;
	while (*cur) {
		cur = &(*cur)->nxt;
	}
	node* new_node = (node*) malloc(sizeof(node));
	new_node->val = x;
	new_node->nxt = *cur;
	*cur = new_node;
}

void pop (node** head) {
	node** cur = head;
	while ((*cur)->nxt->nxt) {
		cur = &(*cur)->nxt;
	}
	free((*cur)->nxt);
	(*cur)->nxt = NULL;
}

void print (node** head) {
	node** cur = head;
	while(*cur) {
		printf("%d\n", (*cur)->val);
		cur = &(*cur)->nxt;
	}
}

/*node* search (node** head, int x) {
	node* cur = *head;
	while (cur->val != x) {
		cur = cur->nxt;
		if (cur == NULL) {
			printf("Not found\n");
			return NULL;
		}
	}
	return cur;
}*/
