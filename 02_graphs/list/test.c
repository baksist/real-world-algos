#include <stdio.h>
#include "list.h"

int main() {
	node* list = (node*) malloc (sizeof(node));
	list = NULL;
	push(&list, 3);
	push(&list, 5);
	push(&list, 4);
	pop(&list);
	print(&list);

	return 0;
}
