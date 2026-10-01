class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        auto get = [&](this auto&& get , int idx , vector<int>& vals) {
            int sum = accumulate(begin(vals) , end(vals) , 0);
            if (sum > target) return;
            if (sum == target) {
                ans.push_back(vals);
                return;
            }
            for (int i = idx ; i<nums.size() ; i++) {
                vals.push_back(nums[i]);
                get(i , vals);
                vals.pop_back();
            }
        };
        vector<int> vals;
        get(0 , vals);
        return ans;
    }
};