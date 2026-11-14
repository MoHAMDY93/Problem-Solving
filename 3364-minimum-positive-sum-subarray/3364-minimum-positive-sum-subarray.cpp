class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int sz = l ; sz <= r ; sz++) {
            int ll = 0, sum = 0;
            for (int rr = 0 ; rr<nums.size(); rr++) {
                sum += nums[rr];
                if (rr - ll + 1 > sz) sum -= nums[ll++];
                if (sum > 0 && rr - ll + 1 >= l) ans = min(ans, sum);
            }
        } 
        return (ans == INT_MAX ? -1 : ans);
    }
};