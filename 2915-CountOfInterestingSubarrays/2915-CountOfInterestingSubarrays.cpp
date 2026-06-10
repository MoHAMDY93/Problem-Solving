// Last updated: 6/10/2026, 7:15:09 PM
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (nums[i] % modulo == k ? 1 : 0);
        }
        
        unordered_map<int, int> count;
        count[0] = 1; // To handle the case where the subarray starts from the beginning
        long long ans = 0;
        
        for (int i = 1; i <= n; ++i) {
            int target = (prefix[i] - k) % modulo;
            if (target < 0) target += modulo; // Ensure it's positive
            if (count.find(target) != count.end()) {
                ans += count[target];
            }
            int current = prefix[i] % modulo;
            count[current]++;
        }
        
        return ans;
    }
};