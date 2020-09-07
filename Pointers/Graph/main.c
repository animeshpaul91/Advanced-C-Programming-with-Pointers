#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

int main(int argc, char **argv)
{
	int n, i;
	printf("\nEnter the number of nodes in the graph\n");
	scanf("%d", &n);
	Node *adj[n];
	for (i=0; i<n; i++)
		adj[i] = NULL;
	createGraph(adj, n);
	printf("\nThe Graph is \n");
	displayGraph(adj, n);
	return 0;
}

void createGraph(Node *adj[], int n) //Creates an Adjacency List
{
	Node *new_node, *prev_node;
	int i, j, ngh, val;
	for (i=0; i<n; i++)
	{
		prev_node = NULL;
		printf("\nEnter the number of neighbours of Node #: %d\n", i);
		scanf("%d", &ngh);
		for (j=0; j<ngh; j++)
		{
			printf("\nEnter the %dth neighbour of %d\n", j, i);
			scanf("%d", &val);
			new_node = (Node *)malloc(sizeof(Node));
			new_node->vertex = val;
			new_node->next = NULL;
			if (adj[i] == NULL)
				adj[i] = new_node;
			else
				prev_node->next = new_node;
			prev_node = new_node;
		}
	}
}

void displayGraph(Node *adj[], int n)
{
	Node *ptr;
	int i;
	for (i=0; i<n; i++)
	{
		ptr = adj[i];
		printf("\nThe neighbours of Node %d are: \n", i);
		while (ptr != NULL)
		{
			printf("\t%d", ptr->vertex);
			ptr = ptr->next;
		}
	}
	printf("\n");
}