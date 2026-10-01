class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        vector<vector<int>> ans;
        vector<int> vals;
        auto get = [&](this auto&& get , int idx , int rem) {
            if (rem == 0) {
                ans.push_back(vals);
                return;
            }
            for (int i = idx ; i<nums.size() ; i++) {
                if (nums[i] > rem) break;

                vals.push_back(nums[i]);
                get(i , rem - nums[i]);
                vals.pop_back();
            }
        };
        get(0 , target);
        return ans;
    }
};