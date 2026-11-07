//// MIDTERM SPRINTS FOR DATA STRUCTURES LESSON ////
////   MULTIPLE ARRAY BASED STACK EXAMPLE      //// 
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA(int val);
void pushB(int val);

int popA();
int popB();

void display_A();
void display_B();

int main(void){
    int val;
    ////// The test conditions were written by Claude.
    display_A();               
    display_B();                 
    val = popA();               
    printf("\npopA: %d\n", val);
    val = popB();                
    printf("\npopB: %d\n", val);

    pushA(10); 
    pushA(20); 
    pushA(30);
    pushB(100); pushB(200);
    display_A();                 
    display_B();                 


    val = popA();                
    printf("\npopA: %d\n", val);
    val = popB();               
    printf("\npopB: %d\n", val);
    display_A();                 
    display_B();              



    for (int i = 1; i <= 5; i++) pushA(i);   
    pushB(7); pushB(8);                     

    pushA(999);                  
    pushB(999);                 
    display_A();                 
    display_B();                

    val = popA();                
    printf("\npopA: %d\n", val);
    pushB(999);               
    pushB(888);                  
    display_B();                

    while ((val = popA()) != -999) printf("\nA'dan: %d", val);  
    while ((val = popB()) != -999) printf("\nB'den: %d", val);  
    display_A();                 
    display_B();                 

    return 0;
}
void pushA(int val){
  if (topB-topA == 1){
    printf("\nSTACK OVERFLOW\n");
    return;  
  }
  else{
    stack[++topA] = val;
  }
}
void pushB(int val){
  if (topB-topA == 1){
    printf("\nSTACK OVERFLOW\n");
    return;
  }
  else{
    stack[--topB] = val;
  }
}
int popA(){
  if(topA == -1){
    printf("\nSTACK UNDERFLOW\n");
    return -999;
  }
  else{
    int data = stack[topA]; 
    stack[topA--] = -1;
    return data;
  }
}
int popB(){
  if(topB == MAX){
    printf("\nSTACK UNDERFLOW\n");
    return -999;
  }
  else{
    int data = stack[topB];
    stack[topB++] = -1;
    return data;
  }
}
void display_A(){
  if (topA == -1){
    printf("The list is empty\n");
    return;
  }
  else{
    for (int i = topA; i >= 0; i--){
      printf("%d\n", stack[i]);
    }
  }
}
void display_B(){
  if (topB == MAX){
    printf("The list is empty\n");
    return;
  }
  else{
    for (int i = topB; i < MAX; i++){
      printf("%d\n", stack[i]);
    }
  }
}
////         Handcoded by chipmaker 𖢥         ////
