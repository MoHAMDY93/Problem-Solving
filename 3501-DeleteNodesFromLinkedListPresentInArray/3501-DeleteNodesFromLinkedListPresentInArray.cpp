// Last updated: 6/10/2026, 7:13:22 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums) , end(nums));
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            if(st.count(curr->val)) {
                if(prev != nullptr) {
                    prev->next = curr->next;
                } else 
                    head = curr->next; 
            } else 
                prev = curr;
            curr = curr->next;
        }   
        return head;
    }
};