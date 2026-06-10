// Last updated: 6/10/2026, 7:28:29 PM
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        ListNode curr = res;
        int carry = 0;
        while (l1 != null && l2 != null) {
            int val = (carry + l1.val + l2.val);
            carry = val / 10;
            curr.next = new ListNode(val % 10);
            l1 = l1.next; l2 = l2.next; curr = curr.next;
            System.out.print(val + " " + carry + "\n");
        }
        while (l1 != null) {
            int val = (carry + l1.val);
            carry = val / 10;
            curr.next = new ListNode(val % 10);
            l1 = l1.next; curr = curr.next;
        }
        while (l2 != null) {
            int val = (carry + l2.val);
            carry = val / 10;
            curr.next = new ListNode(val % 10);
            l2 = l2.next; curr = curr.next;
        }
        if (carry == 1) curr.next = new ListNode(carry);
        return res.next;
    }
}