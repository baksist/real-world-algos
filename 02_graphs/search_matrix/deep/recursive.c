#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct graph {
	int V;
	int E;
	int** adj_matrix;
} graph;

graph fill_graph() {
	graph G;
	scanf("%d", &G.V);
	scanf("%d", &G.E);
	G.adj_matrix = (int**) malloc(sizeof(int) * G.V * G.V);
	for (int i = 0; i < G.V; i++)
		for (int j = 0; j < G.V; j++)
			scanf("%d", (G.adj_matrix + i) + j);
	printf("%d\n", G.adj_matrix[0][1]);
	return G;
}

void print_graph(graph G) {
	printf("Versini: %d\n", G.V);
	printf("Ryobra: %d\n", G.E);
	printf("Adjacency matrix:\n");
	for (int i = 0; i < G.V; i++) {
		for (int j = 0; j < G.V; j++)
			printf("%d ", *(*G.adj_matrix + i)+j);
	}
}

int main(void) {
	graph kek;
	kek = fill_graph();
	print_graph(kek);
	return 0;
}
