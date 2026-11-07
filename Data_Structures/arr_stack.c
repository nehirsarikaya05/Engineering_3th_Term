//// MIDTERM SPRINTS FOR DATA STRUCTURES LESSON ////
////         BASIC ARRAY BASED STACK           //// 
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int st[MAX], top = -1;

void push(int st[], int val);
int  pop(int st[]);
int  peek(int st[]);
void display(int st[]);

int main(void) {
    int val;

    display(st);  // empty    

    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);       

    display(st);  /// 30 20 10

    val = peek(st);
    printf("\nPeek val: %d\n", val);  /// 30

    val = pop(st);
    printf("\nRemoved val: %d\n", val); /// 30

    display(st); /// 20 10

    pop(st); /// 20 out
    pop(st); /// 10 out
    pop(st); /// empty            

    peek(st); /// empty            

    return 0;
}

void push(int st[], int val) {
  if (top == MAX-1){
    printf("Stack overflow.\n");
    return;
  }
  else{
    st[++top] = val;
    return;
  }
}

int pop(int st[]){
  if (top == -1){
    printf("The list is empty.\n");
    return -1;
  }
  int removal = st[top];
  st[top--] = -1;
  return removal;
}

int peek(int st[]){
  if (top == -1){
    printf("The list is empty.\n");
    return -1;
  }
  return st[top];
}

void display(int st[]){
  if (top == -1){
    printf("The list is empty.\n");
    return;
  }
  else{
    for (int i=top; i >= 0; i--){
      printf("%d\n", st[i]);
    }
    return;
  }
}
////         Handcoded by chipmaker 𖢥         ////
