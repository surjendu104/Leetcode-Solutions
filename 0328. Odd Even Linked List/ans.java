/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        List<Integer> odd = new ArrayList<>();
        List<Integer> even = new ArrayList<>();
        ListNode ptr = head;
        int i = 1;
        while (ptr != null) {
            if (i % 2 == 1)
                odd.add(ptr.val);
            else
                even.add(ptr.val);
            i++;
            ptr = ptr.next;
        }
        ListNode dummy = new ListNode(0);
        ListNode ans = new ListNode();
        dummy.next = ans;
        for (int x : odd) {
            ListNode temp = new ListNode(x);
            ans.next = temp;
            ans = temp;
        }
        for (int x : even) {
            ListNode temp = new ListNode(x);
            ans.next = temp;
            ans = temp;
        }
        return dummy.next.next;
    }
}

// Another approach

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head != null) {
            ListNode odd = head;
            ListNode even = head.next;
            ListNode join = even;

            while (odd.next != null && even.next != null) {
                odd.next = even.next;
                odd = odd.next;

                even.next = odd.next;
                even = even.next;

            }
            odd.next = join;
        }
        return head;
    }
}