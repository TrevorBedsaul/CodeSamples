/*Trevor Bedsaul*/
/*tdb7mw*/
/*linkedlist.c*/

#include <stdio.h>
#include <stdlib.h>

struct listNode {
  struct listNode *next;
  int value;
};

struct listNode* head;

int main() {
  //struct linkedList *list; //new list
  head = NULL;
  head = (struct listNode *) malloc(sizeof (struct listNode));
  int n; //number of elements
  printf("Enter n: ");
  scanf("%d", &n);
  int i, x;
  for(i = 0; i < n; i++) {
    struct listNode *tmp; //new node
    tmp = (struct listNode *) malloc(sizeof (struct listNode));
    printf("Enter value %d: ", i+1); //prompts for value
    scanf("%d", &x); //value for new node
    tmp->value = x;
    tmp->next = head->next;
    head->next = tmp;
  }
  int j, y;
  for(j = 0; j < n;  j++) {
    struct listNode *node;
    node = (struct listNode *) malloc(sizeof (struct listNode));
    node = head->next;
    head->next = head->next->next;
    y = node->value;
    printf("%d\n", y);
    free(node);
   }
  free(head);
  return 0;
}
  
