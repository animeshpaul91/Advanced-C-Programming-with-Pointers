/* Creation of a Singly Linked List in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int val;
  struct Node *next;
}Node;

void print(Node *head)
{
  while(head)
  {
    printf("%d\t", head->val);
    head = head->next;
  }
  printf("\n");
}

int main() {
  int i;
  Node *dummy = (Node *)malloc(sizeof(Node));
  dummy->val = -1;
  dummy->next = NULL;
  Node *curr = dummy;
  
  for (i = 0; i < 5; i++)
  {
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = i;
    new->next = NULL;
    curr->next = new;
    curr = curr->next;
  }
  
  Node *start = dummy->next;
  
  print(start);
  print(start);
  
  return 0;
}
