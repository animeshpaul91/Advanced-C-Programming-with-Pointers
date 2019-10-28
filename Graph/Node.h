typedef struct Node
{
	int vertex;
	struct Node *next;
}Node;

void createGraph(Node *adj[], int n);
void displayGraph(Node *adj[], int n);