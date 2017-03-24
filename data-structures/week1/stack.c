#include <stdio.h>
#include <stdlib.h>

/*
 * ---------------------------------------------
 * Stack implementation with linked lists
 * ---------------------------------------------
 */


/*
 * ## NODE
 *
 * Atributes:
 * - key: identifier.
 * - next: pointer to next element.
 */
typedef struct node_{
  int key;
  struct node_* next;
} node;

/*
 * ## STACK
 *
 * Atributes:
 * - top: pointer to top of the stack.
 *
 * Functions:
 * - Push: add an element to the top of the stack.
 * - Pop:  remove the top element of the stack.
 * - get:  show the top element of the stack.
 */
typedef struct stack_{
  // Atributes
  node* top;
  // Functions
  void  (*Push)(struct stack_*, node*);
  void  (*Pop)(struct stack_*);
  node* (*Get)(struct stack_*);
} stack;

/*
 * PUSH
 *
 * IN:
 * - stack = Pointer to stack to which the element
 *           is going to be added.
 * - node  = The node to be added.
 */
void Push(stack* stack, node* node){
  if(stack->top != NULL){
    stack->top->next = node->next;
  }
  stack->top       = node;
}


/*
 * POP
 *
 * IN:
 * - stack = Pointer to stack to which the element
 *           is going to be removed.
 */
void Pop(stack* stack){
  if(stack->top != NULL){
    stack->top = stack->top->next;
  }
}
