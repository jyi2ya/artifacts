#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100009
#define MAX_EDGE 500009
#define MAX_QUERY 200009

int main(int argc, char *argv[])
{
	int N, M, Q;
	srand(atoi(argv[1]));
	N = rand() % MAX_NODE + 1;
	M = rand() % MAX_EDGE + 1;
	Q = rand() % MAX_QUERY + 1;

	N = MAX_NODE;
	M = MAX_EDGE;
	Q = MAX_QUERY;

	printf("%d %d %d\n", N, M, Q);
	while (M--) printf("%d %d\n", rand() % N + 1, rand() % N + 1);
	while (Q--) printf("%d %d\n", rand() % N + 1, rand() % N + 1);
	return 0;
}
