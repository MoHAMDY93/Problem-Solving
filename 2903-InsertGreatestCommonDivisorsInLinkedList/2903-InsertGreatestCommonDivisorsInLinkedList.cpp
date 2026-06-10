// Last updated: 6/10/2026, 7:15:12 PM
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        /*
            18 -> 6 -> 10 -> 3
            while(curr.next != nullptr)
            curr = 18 , next = 6;
            makeNewNode(gcd(18 , 6));
            NodeTemp = curr.next;
            curr.next = newNode;
            newNode.next = temp;
            curr = temp;
        */ 
        ListNode* curr = head;
        while(curr->next != nullptr) {
            ListNode* node = new ListNode(gcd(curr->val , curr->next->val));
            ListNode* temp = curr->next;
            curr->next = node;
            node->next = temp;
            curr = temp;
        }
        return head;
    }
};