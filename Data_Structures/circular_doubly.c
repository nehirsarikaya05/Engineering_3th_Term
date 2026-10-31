//// MIDTERM SPRINTS FOR DATA STRUCTURES LESSON ////
////   CIRCULAR DOUBLY LINKED LIST EXAMPLE    //// 
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *create_ll(struct node *); /// checked
struct node *display(struct node *); /// checked
struct node *display_reverse(struct node *); /// checked
struct node *insert_beg(struct node *); /// checked
struct node *insert_end(struct node *); /// checked
struct node *delete_beg(struct node *); /// checked
struct node *delete_end(struct node *); /// checked
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main(void){
  struct node *start = NULL;
  start = create_ll(start); 
  start = display(start);
  start = display_reverse(start);
  start = insert_beg(start);
  start = display(start);
  start = display_reverse(start);
  start = insert_end(start);
  start = display(start);
  start = display_reverse(start);
  start = delete_beg(start);
  start = display(start);
  start = display_reverse(start);
  start = delete_end(start);
  start = display(start);
  start = display_reverse(start);
  start = delete_node(start);
  start = display(start);
  start = display_reverse(start);
  start = delete_list(start);
  start = display(start);
}

struct node *create_ll(struct node *start){
  printf("Enter digits, -1 to end:\n");
  int num = 0;
  while(1){
    scanf("%d", &num);
    if (num == -1) break;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (start == NULL){
      new -> next = new;
      new -> prev = new;
      new -> data = num;
      start = new;
    }
    else{
      struct node *tail = start -> prev;
      new -> data = num;
      tail -> next = new;
      new -> prev = tail;
      new -> next = start;
      start -> prev = new;
    }
  }
  return start;
}

struct node *display(struct node *start){
  if (start == NULL) return start;
  struct node *traverse = start;
  // yılmaz hoca'nın gösterdiği şekilde...
  printf("\nYOUR LINKED LIST:\n");
  while (traverse -> next != start){
    printf("%d\t", traverse->data);
    traverse = traverse -> next; 
  }
  printf("%d\n", traverse->data); // tail node, or alone member
  return start;
}

struct node *display_reverse(struct node *start){
  if (start == NULL) return start;
  printf("\nYOUR LINKED LIST REVERSED:\n");
  struct node *tail = start->prev;
  struct node *traverse = tail;
  while (traverse -> prev != tail){
    printf("%d\t", traverse->data);
    traverse = traverse -> prev;
  }
  printf("%d\n", traverse->data);
  return start;
}

struct node *insert_beg(struct node *start){
  int num = 0;
  printf("\nEnter digit for insert beg:\n");
  scanf("%d", &num);
  struct node *new = (struct node *)malloc(sizeof(struct node));
  if (start == NULL){
    new -> next = new;
    new -> prev = new;
    new -> data = num;
    start = new;
  }
  else{
    struct node *tail = start->prev;
    new -> next = start;
    new -> prev = tail;
    new -> data = num;
    start -> prev = new;
    tail -> next = new;
    start = new;  
  }
  return start;
}

struct node *insert_end(struct node *start){
  int num = 0;
  printf("\nEnter digit for insert end:\n");
  scanf("%d", &num);
  struct node *new = (struct node *)malloc(sizeof(struct node));
  if (start == NULL){
    new -> next = new;
    new -> prev = new;
    new -> data = num;
    start = new;
  }
  else{
    struct node *tail = start -> prev;
    new -> next = start;
    new -> prev = tail;
    new -> data = num;
    start -> prev = new;
    tail -> next = new;
  }
  return start;
}

struct node *delete_beg(struct node *start){
  if (start == NULL) return start;
  if ((start -> prev == start) && (start -> next == start)){
    free(start);
    return NULL;
  }
  struct node *tail = start -> prev;
  struct node *temp = start;
  start = temp -> next;
  start -> prev = tail;
  tail -> next = start;
  free(temp);
  return start;
}

struct node *delete_end(struct node *start){
  if (start == NULL) return start;
  if ((start -> prev == start) && (start -> next == start)){
    free(start);
    return NULL;
  }
  struct node *tail = start -> prev -> prev;
  struct node *temp = start -> prev;
  tail -> next = start;
  start -> prev = tail;
  free(temp);
  return start;
}

struct node *delete_node(struct node *start){
  int num = 0;
  printf("\nPlease enter the digit that you want to remove from the list:\n");
  scanf("%d", &num);
  if (start == NULL) return start;
  struct node *traverse = start;
  struct node *prenode = start;
  do{
    if (traverse -> data == num){
      prenode -> next = traverse -> next;
      traverse -> next -> prev = prenode;
      if ((start -> next) == start) return NULL; 
      free(traverse);
    }
    prenode = traverse;
    traverse = traverse -> next;
  }while(traverse != start);
  if ((traverse == start) && (start -> next) != start){
    printf("\nDigit is not found in the list.\n");
    return start;
  }
  return start;
}

struct node *delete_list(struct node *start){
  printf("\nLIST IS REMOVING:\n");
  while (start != NULL) start = delete_beg(start);
  return NULL;
}
////         Handcoded by chipmaker 𖢥         ////

