////  QUEUE WITH ENQUEUE, DISPLAY AND FREE FUNCTIONS   ////
////  Early Sprints for Data Structure Lesson ////
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
struct Node{
  int data;
  struct Node *next;
};
struct Queue{
  int size;
  struct Node *rear;
  struct Node *front;
};
typedef struct Node Node;
typedef struct Queue Queue;
bool is_empty(Queue *ptr){
  if ((ptr->size == 0) && (ptr->rear == NULL) && (ptr->front == NULL)) return 1;
  else return 0;
}
void enqueue(int num, Queue *ptr){
  Node *new = (Node *)malloc(sizeof(Node));
  Node *old_rear = ptr -> rear;
  new -> data = num;
  new -> next = NULL;
  if (is_empty(ptr)){
    ptr -> front = new;
    ptr -> rear = new;
    ptr -> size++;
  }
  else{
    old_rear -> next = new;
    ptr -> rear = new;
    ptr -> size++;
  }
}
void display(Queue *ptr){
  Node *current = ptr->front;
  while (current != ptr->rear){
    printf("%p -> %d\n", current, current->data);
    current = current->next;
  }
  printf("%p -> %d\n", current, current->data);
}
void free_queue(Queue *ptr){
  Node *current = ptr->front;
  Node *tmp = ptr->front;
  while (current != ptr->rear){    
    tmp = current;
    current = current -> next;
    free(tmp);
  }
  free(current);
}
int main(void){
  Queue *main = (Queue *)malloc(sizeof(Queue));
  main -> size = 0;
  main -> rear = NULL;
  main -> front = NULL;
  int x = 0;
  srand(time(NULL));
  for (int i = 0; i < 30; i++){
    x = rand() % 100;
    enqueue(x, main);
  }
  display(main);
  free_queue(main);
  free(main);
}
////         Handcoded by chipmaker 𖢥         ////
