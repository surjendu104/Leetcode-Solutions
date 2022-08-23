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
    bool isPalindrome(string &s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i])return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *ptr=head;
        string s="";
        while(ptr!=NULL){
            s+=(char)(ptr->val);
            ptr=ptr->next;
        }
        // string sr=reverse(s.begin(),s.end());
        // if(s.compare(sr)==0)return true;
        // return false;
        return isPalindrome(s);
    }
};