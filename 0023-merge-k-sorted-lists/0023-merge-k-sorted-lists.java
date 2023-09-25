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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        
        for(ListNode node : lists) {
            while(node != null) {
                pq.offer(node);
                node = node.next;
            }
        }
        if(pq.isEmpty()) return null;
        
        ListNode dummy = new ListNode(-1);
        ListNode head = dummy;
        while(!pq.isEmpty()) {
            head.next = pq.poll();
            head = head.next;
        }
        head.next = null;
        return dummy.next;
    }
}