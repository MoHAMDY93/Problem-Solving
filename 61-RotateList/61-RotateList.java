// Last updated: 6/10/2026, 7:27:21 PM
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0)
            return head;
        
        ListNode temp = head;
        int size = 1;
        while(temp.next != null) {
            temp = temp.next;
            size ++;
        }
        k = k % size;
        if(k == 0)
            return head;

        ListNode curr = head , prev = head;
        for(int i = 1 ; i < size - k + 1 ; i++) {
            prev = curr;
            curr = curr.next;
        }
        prev.next = null;   
        temp.next = head;
        head = curr;
        return head;
    }
}