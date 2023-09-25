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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = head, q = head;
        while(n != 0 ) {
            q = q.next;
            n--;
        }
        if(q == null) return head.next;
        // System.out.println(q.val);
        while(q.next != null) {
            p = p.next;
            q = q.next;
        }
        // System.out.println(p.val);
        p.next = p.next.next;
        return head;
    }
}