class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int r = accumulate(nums.begin()+1 , nums.end() , 0);
        int l = 0;
        vector<int> ans(n);
        for (int i=0 ; i<n ; i++) {
            ans[i] = abs(r - l);
            l += nums[i];
            if (i+1 < n)
                r -= nums[i+1];
        }
        return ans;
    }
};