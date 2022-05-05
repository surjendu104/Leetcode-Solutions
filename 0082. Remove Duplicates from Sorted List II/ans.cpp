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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *curr = head, *prev = dummy;
        while (curr)
        {
            bool is_distinct = true;
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                is_distinct = false;
            }
            if (!is_distinct)
            {
                prev->next = curr->next;
                curr = prev->next;
            }
            else
            {
                prev = prev->next;
                curr = prev->next;
            }
        }

        return dummy->next;
    }
};