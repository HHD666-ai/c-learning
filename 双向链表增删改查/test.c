#include <stdio.h>
#include "List.h"

int main(void)
{
    LTNode* phead = LTInit();
    if (phead == NULL)
    {
        return 1;
    }

    LTPushBack(phead, 1);
    LTPushBack(phead, 2);
    LTPushBack(phead, 3);

    LTPrint(phead);

    LTPushFront(phead, 0);
    LTPrint(phead);

    LTPopBack(phead);
    LTPrint(phead);

    LTPopFront(phead);
    LTPrint(phead);

    LTNode* pos = LTFind(phead, 2);
    if (pos != NULL)
    {
        LTInsert(pos, 100);
    }

    LTPrint(phead);

    pos = LTFind(phead, 2);
    if (pos != NULL)
    {
        LTErase(pos);
    }

    LTPrint(phead);

    LTDestroy(phead);

    return 0;
}
