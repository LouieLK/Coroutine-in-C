#include <stdio.h>
#include "src/coroutine_int.h"

int main(void)
{
    struct task_struct task[10];
    struct stack stack;
    struct task_struct *tmp;

    rs_init(&stack);
    for (int i = 0; i < 10; i++) {
        task[i].tfd = i;
        printf("push int the stack %d, return %d\n", i, push_task(&stack, &task[i]));
    }

    for (int i = 0; i < 10; i++) {
    	tmp = get_next(&stack);
        if (tmp)
            printf("pop from stack %d\n", tmp->tfd);
        else
            printf("pop failed\n");
    }

    return 0;
}
