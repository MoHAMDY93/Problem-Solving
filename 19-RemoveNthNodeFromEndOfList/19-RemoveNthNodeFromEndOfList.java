// Last updated: 6/10/2026, 7:28:02 PM
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
        ListNode dummy = new ListNode(0);
        ListNode p1 = head, p2 = head, curr = dummy;
        int cnt = 1;
        while(cnt < n){
            p2 = p2.next;
            cnt++;
        }
        while(p2.next != null) {
            curr.next = p1;
            curr = curr.next;
            p1 = p1.next;
            p2 = p2.next;
        }
        curr.next = p1.next;
        return dummy.next;
    }
}