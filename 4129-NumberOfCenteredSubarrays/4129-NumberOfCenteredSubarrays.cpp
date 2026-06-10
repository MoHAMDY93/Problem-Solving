// Last updated: 6/10/2026, 7:09:37 PM
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_map<long long, int> freq;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                freq[nums[j]]++;

                if (freq.count(sum)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
