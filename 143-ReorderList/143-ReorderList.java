// Last updated: 6/10/2026, 7:26:27 PM
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
        // Can Solved using o(1) extra memory
        
        if (head == null || head.next == null) return;
        // Split the list in two halves;
        ListNode slow = head , fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // Reverse the second half
        ListNode prev = null , curr = slow.next;
        slow.next = null;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        // Merge the two lists
        ListNode first = head , second = prev;
        while (second != null) {
            ListNode t1 = first.next , t2 = second.next;
            first.next = second;
            second.next = t1;
            first = t1;
            second = t2;
        }
    }
}