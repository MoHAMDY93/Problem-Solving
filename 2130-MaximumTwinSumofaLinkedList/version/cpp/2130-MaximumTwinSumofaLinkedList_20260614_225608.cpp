// Last updated: 6/14/2026, 10:56:08 PM
// Using slow & fast pointer to get the mid
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    int pairSum(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head;
16        while (fast != nullptr) {
17            slow = slow->next;
18            fast = fast->next->next;
19        }
20        // now slow is on the start node of the second half
21        ListNode* curr = slow;
22        ListNode* prev = nullptr;
23        while (curr != nullptr) {
24            ListNode* new_curr = curr->next;
25            curr->next = prev;
26            prev = curr;
27            curr = new_curr;
28        }
29        // now the prev is the end of the second half
30        // we set the left pointer to head and right pointer to prev and keep moving until meeting nullptr
31        int ans = 0;
32        ListNode* left = head;
33        ListNode* right = prev;
34        while (right != nullptr) {
35            ans = max(ans , left->val + right->val);
36            left = left->next;
37            right = right->next;
38        }
39        return ans;
40    }
41};