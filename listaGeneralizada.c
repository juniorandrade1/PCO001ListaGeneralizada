/*
  Lista generalizada
*/
 
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

void compare(void *v, int op, Node *x) {
  if(op == 1) {
    if(*(int *)v == *(int *)x->v){
        printf("\nItem Encontrado!");
    }
    return;
  }
  else if(op == 2) {
    if(*(long long *)v == *(long long*)x->v){
        printf("\nItem Encontrado!");
    }
    return;
  }
  else if(op == 3) {
    if(*(char *)v == *(char *)x->v){
       printf("\nItem Encontrado!");
    }
  }
}

void find_item(void *v, int i, Node *x){
    if(x == NULL) return;
    if(x->op > 0){
        compare(v,i,x);
    }else {
        Lista *ax = (Lista*)x->v;
        find_item(v,i,ax->root);
    }
    find_item(v,i, x->nxt);
}

void head(Node *x){
   if(x == NULL) printf("\nLista Vazia");
   else{
    printf("\nPrimeiro elemento da lista: ");
    printType(x);
   }
}
 
 
int main() {
  Lista *l0 = createLista();
  l0->root = l0->lst = NULL;
 
  int arr0[] = {5, 9};
  insertListType(l0, &arr0[0], 1);
  insertListType(l0, &arr0[1], 1);
 
  Lista *l1 = createLista();
  l1->root = l1->lst = NULL;
  char arr1[] = {'c', 'e'};
 
  insertListType(l1, &arr1[0], 3);
  insertListType(l1, &arr1[1], 3);
 
  printf("Lista 0\n");
  printList(l0->root);
  printf("\n");
 
  printf("Lista 1\n");
  printList(l1->root);
  printf("\n");
 
 
  printf("Inserindo lista 0 na lista 1\n");
  insertListType(l0, l1, 0);
  printList(l0->root);
  printf("\n");
 
 
  int arr3[] = {55, 190};
  insertListType(l1, &arr3[0], 1);
  insertListType(l1, &arr3[1], 1);
 
  printList(l1->root);
  printf("\n");
  printList(l0->root);
  printf("\n");
 
  char x = 'e';
  find_item(&x, 3, l0->root);
 
  head(l0->root);
  printf("\n");
 
  return 0;
}
 