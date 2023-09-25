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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null)
            return;

        ListNode slow = head, fast = head;

        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode mid = slow.next;
        slow.next = null;
        
        mid = reverse(mid);

        while(mid != null) {
            ListNode tmp1 = head.next;
            ListNode tmp2 = mid.next;

            head.next = mid;
            mid.next = tmp1;

            head = tmp1;
            mid = tmp2;
        }
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null;

        while(head != null) {
            ListNode tmp = head.next;
            head.next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
}