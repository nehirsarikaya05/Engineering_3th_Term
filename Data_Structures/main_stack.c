////  Classical STACK with pop, push, print  ////
////  Early Sprints for Data Structure Lesson ////
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>
//////// STACK INITIALIZE /////////
struct Node{
  int data;
  struct Node *next;
};
struct Stack{
  struct Node *top;
  int size;
};
typedef struct Node Node;
typedef struct Stack Stack;

/////// FUNCTION INITILIAZE /////////
void init(Stack *s); 
int is_empty(Stack *s);
void push(Stack *s, int x); 
void print_stack(Stack *s);
int pop(Stack *s, int *out); 
/////////// MAIN ////////////////
int main (void){
  int out = 0;
  Stack main;
  init(&main);
  push(&main, 50);
  push(&main, 40); 
  push(&main, 35);
  print_stack(&main);
  pop(&main, &out);
  push(&main, 62);
  print_stack(&main);
  push(&main, 41);
  print_stack(&main);
}
void init(Stack *s){
  s -> top = NULL;
  s -> size = 0;
}
int is_empty(Stack *s){
  if (s -> top == NULL){
    return 1;
  }
  else return 0;
}
void push(Stack *s, int x){
  Node *new = malloc(sizeof(Node));
  if (new == NULL) return;
  if (is_empty(s)){
    new -> data = x;
    new -> next = NULL;
    s -> top = new;
    s -> size++;
  }
  else{
    Node *current = s -> top;
    new -> data = x;
    new -> next = current;
    s -> top = new;
    s -> size++;
  }
}
void print_stack(Stack *s){
  Node *current = s -> top;
  if (current == NULL) return;
  printf("///// STACK ///// \n");
  while (current != NULL){
    printf("%d\n", current->data);
    current = current -> next;
  }
  printf("///// END /////\n\n");
}
int pop(Stack *s, int *out){
    if (is_empty(s)) return 0;
    Node *x = s -> top;
    (*out) = x -> data;
    s -> top = x -> next;
    s -> size--;
    free(x);
    return 1;
}
////         Handcoded by chipmaker 𖢥         ////
