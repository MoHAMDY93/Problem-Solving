// Last updated: 6/10/2026, 7:08:53 PM
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int , int> mp;
        auto rev = [&](int n) -> int {
            int ret = 0;
            while (n) {
                ret = ret * 10 + (n % 10);
                n /= 10;
            }
            return ret;
        };
        int ans = INT_MAX;
        for (int i=0 ; i<nums.size() ; i++) {
            // int mir = rev(nums[i]);
            if (mp.count(nums[i])) ans = min(ans , i - mp[nums[i]]);
            mp[rev(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};