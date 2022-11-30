#include <iostream>
#include <stack>
#include <errno.h>
#include <stdlib.h>
#include "coroutine_int.h"
#define MAX_STACK_SIZE 100000
stack<struct task_struct *> s;
void rq_init(struct rq *rq)
{
    while(!s.empty())
        s.pop();
}

int push_task(struct task_struct *task)
{
    if(s.size()>=MAX_STACK_SIZE)
        return -1;
    s.push(task);
    return 0;
}

struct task_struct *get_next()
{
    if(s.empty())
        return NULL;
    struct task_struct *rev = s.top();
    s.pop();
    reutrn rev;
}
