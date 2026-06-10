// Last updated: 6/10/2026, 7:13:03 PM
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums) , end(nums));
        int ans = 0 , prev = -1e9;;
        for(auto c : nums) {
            int l = max(c - k , prev+1);
            if(l <= c + k) prev = l , ans++;
            // ans += min(2*k+1 , v);
        }
        return ans;
    }
};