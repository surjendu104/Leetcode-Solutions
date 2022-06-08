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



/*Runtime: 12 ms, faster than 21.24% of C++ online submissions for Partition List.
Memory Usage: 10.3 MB, less than 75.28% of C++ online submissions for Partition List.*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0),node2(0);
        ListNode *p1 = &node1,*p2 = &node2;

        while(head){
            if(head->val<x){
                p1=p1->next=head;
            }
            else{
                p2 = p2->next= head;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2.next;
        return node1.next;
    }
};