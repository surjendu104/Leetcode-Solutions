/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next || left == right)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        ListNode *tail = prev->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *nxtP = prev->next, *nxtT = tail->next->next;
            prev->next = tail->next;
            tail->next->next = nxtP;
            tail->next = nxtT;
        }
        return dummy->next;
    }
};