////// MIDTERM SPRINTS FOR DATA STRUCTURES LESSON ////
////// STACK BASED QUEUE EXAMPLE ////
////         Handcoded by chipmaker 𖢥         ////

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
    int size;
};

struct stack *inStack;
struct stack *outStack;

struct node *pop(struct stack *st);
struct node *push(struct stack *st, int num);
void enqueue(int num);
void dequeue();

//
// GLOBAL -->
//

struct node *pop(struct stack *st) {
    if (st->size == 0) return NULL;
    struct node *out = st->top;
    st->top = out->next;
    out->next = NULL;
    st->size--;
    return out;
}

struct node *push(struct stack *st, int num) {
    if (st->size == MAX) return NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = st->top;
    st->top = new;
    st->size++;
    return new;
}

void enqueue(int num) {
    if (inStack->size == MAX) return;
    push(inStack, num);
}

void dequeue() {
    if (outStack->size == 0 && inStack->size > 0) {
        while (inStack->size > 0) {
            struct node *transfer = pop(inStack);
            push(outStack, transfer->data);
            free(transfer);
        }
    }
    if (outStack->size > 0) {
        pop(outStack);
    }
}

// This function was written by Claude for testing.
// Prints the queue from front to back.
void printQueue(const char *label) {
    int arr[MAX], n = 0;
    printf("%-24s: ", label);
    for (struct node *p = outStack->top; p; p = p->next)
        printf("%d ", p->data);
    for (struct node *p = inStack->top; p; p = p->next)
        arr[n++] = p->data;
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

//
// MAIN -->
//

// This code was written on paper.
// The test conditions were written by Claude.
int main(void) {
    inStack = (struct stack *)malloc(sizeof(struct stack));
    inStack->top = NULL;
    inStack->size = 0;
    outStack = (struct stack *)malloc(sizeof(struct stack));
    outStack->top = NULL;
    outStack->size = 0;

    enqueue(10);
    enqueue(15);
    enqueue(20);
    printQueue("enqueue 10,15,20");       // expected: 10 15 20

    dequeue();
    printQueue("dequeue #1");             // expected: 15 20

    dequeue();
    printQueue("dequeue #2");             // expected: 20

    dequeue();
    printQueue("dequeue #3");             // expected: (empty)

    dequeue();
    printQueue("dequeue on empty queue"); // expected: no crash

    for (int i = 1; i <= 7; i++) enqueue(i * 10);
    printf("MAX test: in size=%d (expected 5)\n", inStack->size);

    return 0;
}

////         Handcoded by chipmaker 𖢥         ////