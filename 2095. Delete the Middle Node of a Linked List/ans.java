/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head.next==null)return null;
        int n=0;
        ListNode ptr = head;
        while(ptr!=null) {
            n++;
            ptr=ptr.next;
        }
        // System.out.println(n);
        n=n/2;
        ListNode q=head;
        while(n--!=1) {
            q=q.next;
        }
        q.next = q.next.next;
        return head; 
    }
}