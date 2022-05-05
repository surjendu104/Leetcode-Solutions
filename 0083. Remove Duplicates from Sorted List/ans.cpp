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
        unordered_map<int, int> m;
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next = NULL;
        list<int> l;
        ListNode *p = head;
        while (p != NULL)
        {
            m[p->val]++;
            p = p->next;
        }
        // for (auto x : m)
        // cout << x.first << " " << x.second << endl;
        // sort(m.begin(),m.end());
        for (auto c : m)
        {
            p->val = c.first;
            p->next = NULL;
        }
        return l.front();
    }
};