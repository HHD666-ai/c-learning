#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void TestStack()
{
    Stack st;
    StackInit(&st);

    StackPush(&st, 10);
    StackPush(&st, 20);
    StackPush(&st, 30);

    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }

    printf("\n");

    StackDestroy(&st);
}

void TestQueue()
{
    Queue q;
    QueueInit(&q);

    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }

    printf("\n");

    QueueDestroy(&q);
}

int main()
{
    TestStack();
    TestQueue();

    return 0;
}
