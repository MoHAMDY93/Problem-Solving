class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        vector<vector<int>> ans;
        vector<int> vals;
        auto get = [&](this auto&& get , int idx , int rem) {
            if (rem == 0) {
                ans.push_back(vals);
                return;
            }
            for (int i = idx ; i<nums.size() ; i++) {
                if (i > idx && nums[i] == nums[i-1]) continue;
                if (nums[i] > rem) break;
                
                vals.push_back(nums[i]);
                get(i+1 , rem - nums[i]);
                vals.pop_back();
            }
        };
        get(0 , target);
        return ans;
    }
};