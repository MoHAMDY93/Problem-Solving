// Last updated: 6/10/2026, 7:16:40 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int left = 0; // Left boundary of the current valid window
        int last_min = -1, last_max = -1; // Last positions of minK and maxK

        for (int right = 0; right < n; right++) {
            if (nums[right] < minK || nums[right] > maxK) {
                left = right + 1; // Reset the window
                last_min = -1;
                last_max = -1;
            } else {
                if (nums[right] == minK) last_min = right;
                if (nums[right] == maxK) last_max = right;
                
                if (last_min != -1 && last_max != -1) {
                    int start = min(last_min, last_max);
                    ans += max(0, start - left + 1);
                }
            }
        }
        return ans;
    }
};