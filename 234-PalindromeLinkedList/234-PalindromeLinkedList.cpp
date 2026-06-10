// Last updated: 6/10/2026, 7:25:31 PM
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
    bool isPalindrome(ListNode* head) {
        string str = "";
        for(ListNode* curr = head ; curr != nullptr ; curr = curr->next) str.push_back((char)(curr->val + '0'));
        for(int i=0 , j = str.size()-1 ; i < j ; i++ , j--) {
            if(str[i] != str[j]) return false;
        }
        return true;
        
    }
};