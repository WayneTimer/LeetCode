/*
Time: O(n)
Space: O(n)
Runtime: 36ms

Hint: Recursion.

by Timer [linyicx@126.com]
2015.09.13
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void calc(ListNode* l1, ListNode* l2, int g)
    {
        if (l1 && l2)
        {
            l1->val += l2->val + g;
            if (l1->val >= 10)
            {
                l1->val -= 10;
                g = 1;
            }
            else
            {
                g = 0;
            }
            if (!l1->next && (l2->next || g))
                l1->next = new ListNode(0);
            calc(l1->next,l2->next,g);
        }
        else if (l1)
        {
            l1->val += g;
            if (l1->val >= 10)
            {
                l1->val -= 10;
                g = 1;
            }
            else
            {
                g = 0;
            }
            if (!l1->next && g)
                l1->next = new ListNode(0);
            calc(l1->next,NULL,g);
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        calc(l1,l2,0);
        return l1;
    }
};
