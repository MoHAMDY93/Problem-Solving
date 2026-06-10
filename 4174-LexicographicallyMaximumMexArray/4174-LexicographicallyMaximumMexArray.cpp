// Last updated: 6/10/2026, 7:08:38 PM
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin() , nums.end());
        vector<int> freq(mx + 2 , 0);
        for (auto i : nums) freq[i]++;
        vector<int> ans;
        int mex = 0 , i = 0;
        while (i < n) {
            while (freq[mex] > 0) mex++;
            if (mex == 0) {
                ans.push_back(mex);
                freq[nums[i]]--;
                i++;
                continue;
            }
            set<int> seen;
            while (i < n && seen.size() < mex) {
                if (nums[i] < mex) seen.insert(nums[i]);
                freq[nums[i]]--;
                i++;
            }
            ans.push_back(mex);
            mex = 0;
        }
        return ans;
    }
};