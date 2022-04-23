class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *next = head->next;
        head->next = swapPairs(head->next->next);
        next->next = head;

        return next;
    }
};