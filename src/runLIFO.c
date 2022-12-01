#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "coroutine_int.h"
#define MAX_STACK_SIZE 100000
void rs_init(struct stack *stack)
{
    stack->top=0;
}

int push_task(struct stack *stack,struct task_struct *task)
{
    if(stack->top>=MAX_STACK_SIZE)
        return -1;
    stack->stack[stack->top++]=task;
    return 0;
}

struct task_struct *get_next(struct stack *stack)
{
    if(stack->top==0)
        return NULL;
    return stack->stack[--stack->top];
}
