/*
 * stack.h - Implementation of stack data structure 
 * Date: 13-August-2018
 *
 * Created By: Adarsh Bhalotia
 */

#include<stdlib.h>

struct Stack
{
	int *arr;
	int top;
	unsigned len;
};

struct Stack* create_stack(unsigned len)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->len = len;
	stack->arr = (int*) malloc(stack->len*sizeof(int));
	return stack;
}

int is_empty(struct Stack stack)
{
	if(stack.top == -1)
		return 1;
	else
		return 0;
}

int is_full(struct Stack stack)
{
	if(stack.top == stack.len - 1)
		return 1;
	else
		return 0;
}

void push(struct Stack stack,int value)
{
	if(!is_full(stack))
		stack.arr[++stack.top] = value;
	return;
}

int pop(struct Stack stack)
{
	if(!is_empty(stack))
		return stack.arr[stack.top--];
	else
		return -1;
}
