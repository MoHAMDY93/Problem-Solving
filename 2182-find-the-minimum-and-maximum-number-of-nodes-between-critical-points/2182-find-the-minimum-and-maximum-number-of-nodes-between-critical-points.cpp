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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* mid = nullptr;
        ListNode* nxt = head;
        int cnt = 1 , left_most = -1 , right_most = -1 , prev_critical = -1 , mn = INT_MAX;
        for ( ; nxt != nullptr ; prev = mid , mid = nxt , nxt = nxt->next , cnt++) {
            bool ok = (prev && mid && ((mid->val > prev->val && mid->val > nxt->val) || (mid->val < prev->val && mid->val < nxt->val)));
            if (!ok) continue;
            // cout << "in: " << cnt << '\n';
            // cout << prev_critical << '\n';
            // critical point found
            // 1) update the min_dist
            if (prev_critical != -1) mn = min(mn , cnt - prev_critical);
            prev_critical = cnt;
            // 2) update the left_most && right_most
            if (left_most == -1) left_most = cnt;
            else right_most = cnt;

        }
        if (mn == INT_MAX) return {-1 , -1};
        return {mn , right_most - left_most};
    }
};