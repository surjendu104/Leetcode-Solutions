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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode* start = head, *end = head,*p = head;
        while(p!=NULL) {
            if(cnt==k-1)start = p;
            p = p->next;
            cnt++;
        }
        cout<<"cnt : "<<cnt<<endl;
        p = head;
        int pos = 1;
        while(p!=NULL) {
            if(pos==cnt-k+1)end = p;
            p = p->next;
            pos++;
        }
        cout<<start->val<<' '<<end->val<<'\n';
        int tmp = start->val;
        start->val = end->val;
        end->val = tmp;
        return head;
    }
};