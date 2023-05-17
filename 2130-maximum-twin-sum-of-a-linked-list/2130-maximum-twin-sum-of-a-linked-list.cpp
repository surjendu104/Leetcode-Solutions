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
    int pairSum(ListNode* head) {
        ListNode* ptr = head;
        vector<int>v;
        while(ptr!=NULL) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int ans = INT_MIN;
        for(int i = 0; i < v.size(); ++i) {
            ans = max(v[i]+v[v.size()-1-i], ans);
        }
        return ans;
    }
};