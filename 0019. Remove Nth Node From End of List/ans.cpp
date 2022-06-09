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
#include <bits/stdc++.h>
using namespace std;


/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.8 MB, less than 33.62% of C++ online submissions for Remove Nth Node From End of List.*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head,*q=head,*r=head;
        int count=0;
        while(p!=NULL){
            p=p->next;
            count++;
        }
        if(count==n)return head->next;
        while(count--){
            q=q->next;
        }
        q->next=q->next->next;
        return r;
    }
};