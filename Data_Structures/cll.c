////  CIRCULAR LINKED LIST INTRO - NO FREE FUNCTION  ////
////  Early Sprints for Data Structure Lesson ////
//// Hastayken yatakta telefonda kodladım, 17 Ekim ////
////         Handcoded by chipmaker 𖢥         ////
#include <stdio.h>
#include <stdlib.h>
struct node{
     int data;
     struct node *next;
};
struct node *create_cll(struct node *start){
    int num = 0;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    start = new;
    struct node *temp = start;
    scanf("%d", &num);
    new -> data = num;
    new -> next = start;
    if (num == -1) return start;
    while (num != -1){
        struct node *nnew = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &num);
        if (num == -1) break;
        nnew -> data = num;
        nnew -> next = start;
        while (temp -> next != start){
            temp = temp -> next;
        }
        temp -> next = nnew;
    }
    return start;
}
void display(struct node *start){
    struct node *temp = start;
    while (temp -> next != start){
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
    printf("%d\n", temp -> data);
}
int main(void){
   struct node *head = NULL;
   head = create_cll(head);
   display(head);
}
////         Handcoded by chipmaker 𖢥         ////