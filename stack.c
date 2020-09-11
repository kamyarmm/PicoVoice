/*[C] Design and implement a stack class (i.e. struct with accompanying functions).
The interface should allow storing any data type. Describe different implementation
strategies and compare their pros and cons. What is the best approach in a
real-time system? What is the best approach when memory resources are very
limited? You can use “malloc” and “free” functions.*/


// there are two method for implementation : linked list  and array
// linkelist is : can grow and shrink base on the needs at runtime but it need extra memroy because of pointers
// Array: eas of implementation.  it is not dynamic so it can not be dynamic in respect to grow and shrink at runtime
// here I implemented the linkedlist solution.
// the issue here is that memcpy doesn't check the validity of the destination and source


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack 
{
	int top;
	unsigned int item_size;
	unsigned int size;
	void *buff;
} stack_t;

// creat and init stack 
stack_t * creat_stack(unsigned int size, unsigned int item_size)
{
	stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
	stack->top = -1;
	stack->size = size;
	stack->item_size = item_size;
	stack->buff = (void*)(malloc(size * item_size));
  return stack;
}

// Stack is full if top is equal to the last index 
int is_full(stack_t* stk) 
{ 
    return stk->top == stk->size - 1; 
} 
  
// Stack is empty if top is equal to -1 
int is_empty(stack_t* stk) 
{ 
    return stk->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
bool  push(stack_t* stk, void* item) 
{ 
    if((stk == NULL) || (item ==NULL) || is_full(stk))
      return false;
	
    memcpy(stk->buff + (++stk->top * stk->item_size), item, stk->item_size);
   return true;
} 
  
// Function to remove an item from stack.  It decreases top by 1 
bool pop(struct stack* stk, void* item) 
{ 
  if((stk == NULL) || (item ==NULL) || is_empty(stk))
   return false;
    
	memcpy(item, stk->buff + (stk->top-- * stk->item_size), stk->item_size);
   
    return true;
} 
