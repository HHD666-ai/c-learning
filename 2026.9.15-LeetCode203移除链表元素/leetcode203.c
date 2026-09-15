/* struct ListNode is provided by LeetCode. */
#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val)
{
    while (head != NULL && head->val == val)
    {
        struct ListNode* del = head;
        head = head->next;
        free(del);
    }

    struct ListNode* cur = head;

    while (cur != NULL && cur->next != NULL)
    {
        if (cur->next->val == val)
        {
            struct ListNode* del = cur->next;
            cur->next = del->next;
            free(del);
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}
