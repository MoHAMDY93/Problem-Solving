class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums), end(nums));
        int ans = -1;
        while (k--) ans = pq.top(), pq.pop();
        return ans; 
    }
};