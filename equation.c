/*
  Aplicaçao lista generalizada
  Equações
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct lista Lista;

struct node {
   int op;
   void *v;
   Node *nxt;
};

struct lista {
  Node *root;
  Node *lst;
};

Lista *createLista() {
  Lista *ax = (Lista*)malloc(sizeof(Lista*));
  ax->root = NULL;
  ax->lst = NULL;
  return ax;
}

size_t sizeTypes[] = {sizeof(Lista*), sizeof(int), sizeof(long long), sizeof(char)};

Node *createNode() {
  Node *no = (Node*)malloc(sizeof(Node*));
  return no;
}

Node *createNodeType(void *v, int type) {
  Node *new_node = createNode();
  new_node->op = type;
  new_node->v = malloc(sizeTypes[type]);
  int i;
  for (i = 0; i < sizeTypes[type]; i++) {
    *(char *)(new_node->v + i) = *(char *)(v + i);
  }
  new_node->nxt = NULL;
  return new_node;
}

void insertListType(Lista *l, void *v, int type) {
  Node *s = createNodeType(v, type);
  if(l->root == NULL) {
    l->root = s;
    l->lst = s;
  }
  else {
    l->lst->nxt = s;
    l->lst = s;
  }
}

void printType(Node *x) {
  if(x->op == 1) {
    printf("%d ", *(int *)x->v);
  }
  else if(x->op == 2) {
    printf("%lld ", *(long long *)x->v);
  }
  else if(x->op == 3) {
    printf("%c ", *(char *)x->v);
  }
}

void printList(Node *x) {
  if(x == NULL) return;
  printf("( [%d] ", x->op);
  if(x->op > 0) printType(x);
  else {
    Lista *ax = (Lista*)x->v;
    printList(ax->root);
  }
  printf(")");
  printList(x->nxt);
}

void printListWithoutParenteses(Node *x) {
  if(x == NULL) return;
  if(x->op > 0) printType(x);
  else {
    Lista *ax = (Lista*)x->v;
    printListWithoutParenteses(ax->root);
  }
  printListWithoutParenteses(x->nxt);
}



int main() {
  Lista *l0 = createLista();  
  l0->root = l0->lst = NULL;
  
  int v[] = {5, 9, 10};
  char op[] = {'+', '-'};

  insertListType(l0, &v[0], 1);
  insertListType(l0, &op[0], 3);
  insertListType(l0, &v[1], 1);
  insertListType(l0, &op[1], 3);
  insertListType(l0, &v[2], 1);
 
  
  printf("Lista 0\n");
  printListWithoutParenteses(l0->root);
  printf("\n");

  return 0;
}