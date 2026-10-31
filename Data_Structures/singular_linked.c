//// MIDTERM SPRINTS FOR DATA STRUCTURES LESSON ////
//// Singular Linked List with Reema Thareja Functions ////
////         Handcoded by chipmaker 𖢥          ////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
  int data;
  struct node *next;
};
struct node *create_ll(struct node *); ///checked
struct node *display(struct node *);  ///checked
struct node *insert_beg(struct node *); ///checked
struct node *insert_end(struct node *); ///checked 
struct node *insert_before(struct node *); ///checked (WILL CAUSE PROBLEM FOR NOT FOUND VALUES) 
struct node *insert_after(struct node *); ///checked (WILL CAUSE PROBLEM FOR NOT FOUND VALUES)
struct node *delete_beg(struct node *); ///checked
struct node *delete_end(struct node *); ///checked
struct node *delete_node(struct node *); ///checked (WILL CAUSE PROBLEM FOR END AND BEGINING)
struct node *delete_after(struct node *); ///checked
struct node *delete_list(struct node *); ///checked
struct node *sort_list(struct node *); ///checked 
int main(void){
  struct node *start = NULL;
  start = create_ll(start);
  start = display(start);
  start = insert_beg(start);
  start = display(start);
  start = insert_end(start);
  start = display(start);
  start = insert_before(start);
  start = display(start);
  start = insert_after(start);
  start = display(start);
  start = delete_beg(start);
  start = display(start);
  start = delete_end(start);
  start = display(start);
  start = delete_node(start);
  start = display(start);
  start = delete_after(start);
  start = display(start);
  start = sort_list(start);
  start = display(start);
  start = delete_list(start);
  start = display(start);
}
struct node *create_ll(struct node *start){
  int num = 0;
  printf("Enter number, -1 to end.\n");
  while(num != -1){
    scanf("%d", &num);
    if (num == -1) break;
    struct node *new = (struct node *)malloc(sizeof(struct node)); // don't forget to free it!!!
    new -> data = num;
    new -> next = NULL;
    if (start  == NULL){
      start = new;
    }
    else{
      struct node *traverse = start; 
      while(traverse->next != NULL){
        traverse = traverse -> next;
      }
      traverse -> next = new;
    }
  }
  return start;
}
struct node *display(struct node *start){
  struct node *traverse = start;
  if (traverse == NULL) printf("\nList is empty.\n");
  else printf("\nYOUR LINKED LIST:\n");
  while(traverse != NULL){
    printf("%d\n", traverse -> data);
    traverse = traverse -> next;
  }
  return start;
}
struct node *insert_beg(struct node * start){
  printf("\nEnter number to insert beg:\n");
  int num = 0;
  scanf("%d", &num);
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new -> data = num;
  new -> next = start;
  start = new;
  return start;
}
struct node *insert_end(struct node *start){
  printf("\nEnter number to insert end:\n");
  int num = 0;
  scanf("%d", &num);
  struct node *traverse = start;
  struct node *new = (struct node *)malloc(sizeof(struct node));  
  new -> data = num;
  new -> next = NULL;
  while(traverse->next != NULL){
    traverse = traverse -> next;
  }
  traverse -> next = new;
  return start;
}
struct node *insert_before(struct node *start){
  printf("\nEnter number to insert before:\n");
  int num, val = 0;
  scanf("%d", &num);
  printf("\nEnter reference node data:\n");
  scanf("%d", &val);
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new -> data = num;
  struct node *traverse = start;
  struct node *prenode = start;
  while (traverse -> data != val){
    prenode = traverse;
    traverse = traverse -> next;
  }
  prenode -> next = new;
  new -> next = traverse;
  return start;
}
struct node *insert_after(struct node *start){
  int num, val = 0;
  printf("\nEnter number to insert after:\n");
  scanf("%d", &num);
  printf("\nEnter reference node data:\n");
  scanf("%d", &val);
  struct node *traverse = start;
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new -> data = num;
  while(traverse -> data != val){
    traverse = traverse -> next;
  }
  struct node *temp = traverse -> next;
  traverse -> next = new;
  new -> next = temp;
  return start;
}
struct node *delete_beg(struct node *start){
  printf("\nFirst data is deleting...\n");
  struct node *temp = start;
  start = start -> next;
  free(temp);
  return start;
}
struct node *delete_end(struct node *start){
  printf("\nLast data is deleting...\n");
  struct node *traverse = start;
  while(traverse->next->next != NULL){
    traverse = traverse->next;
  }
  struct node *temp = traverse -> next;
  traverse -> next = NULL;
  free(temp);
  return start;
}
struct node *delete_node(struct node *start){
  int val = 0;
  bool flag = 0;
  printf("\nEnter num for deleting:\n");
  scanf("%d", &val);
  struct node *traverse = start;
  struct node *prenode = start;
  while(traverse -> data != val){
    prenode = traverse;
    traverse = traverse -> next;
    if (traverse -> next == NULL){
      flag = 1;
      break;
    }
  }
  if (!flag){
    prenode -> next = traverse -> next;
    free(traverse);
  }
  else{
    printf("\nYour entry is not in linked list.\n");
  }
  return start;
}
struct node *delete_after(struct node *start){
  int val = 0;
  printf("\nEnter the value that you want to delete after:\n");
  scanf("%d", &val);
  struct node *traverse = start;
  while(traverse -> data != val){
    traverse = traverse -> next;
  }
  struct node *temp = traverse -> next;
  traverse -> next = temp -> next;
  free(temp);
  return start;
}
struct node *delete_list(struct node *start){
  printf("\nALL LIST IS REMOVING\n");
  if (start == NULL) return start;
  struct node *traverse = start;
  struct node *prenode = start;
  while(traverse -> next != NULL){
    prenode = traverse;
    traverse = traverse -> next;
    free(prenode);  
  }
  free(traverse);
  return NULL;
}
struct node *sort_list(struct node *start){
  int pre = 0;
  int post = 0;
  int count = 0;
  int bound = 0;
  printf("\nSORTED VERSION\n");
  struct node *ptr = start;
  while(ptr -> next != NULL){
    ptr = ptr -> next;
    count++;
  }
  while(bound != count){  
    struct node *traverse = start;
    while (traverse->next != NULL){
      pre = traverse -> data;
      post = traverse -> next -> data;
      if (pre > post){
        traverse -> data = post;
        traverse -> next -> data = pre;
      }
      traverse = traverse -> next;
    }
    bound++;
  }
  return start;
}
////         Handcoded by chipmaker 𖢥          ////

