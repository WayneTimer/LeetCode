/*
Time: O(n)
Space: O(1)
Runtime: 4ms

Hint:
Two lists are sorted from small to big.

by Timer [linyicx@126.com]
2015.11.20
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ret,*last;
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val <= l2->val)
    {
        ret = l1;
        l1 = l1->next;
    }
    else
    {
        ret = l2;
        l2 = l2->next;
    }
    last = ret;
    while (l1)
    {
        while (l2 && l2->val < l1->val)
        {
            last->next = l2;
            last = last->next;
            l2 = l2->next;
        }
        if (!l2)
        {
            last->next = l1;
            break;
        }
        last->next = l1;
        last = last->next;
        l1 = l1->next;
    }
    if (!l1 && l2)
    {
        last->next = l2;
    }
    return ret;
}
