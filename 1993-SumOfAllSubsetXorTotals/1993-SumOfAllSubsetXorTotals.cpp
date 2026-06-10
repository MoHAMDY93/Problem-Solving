// Last updated: 6/10/2026, 7:19:13 PM
class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& subsets) {
        subsets.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);             
            backtrack(i + 1, nums, current, subsets); 
            current.pop_back();                     
        }
    }

    vector<vector<int>> getSubsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current;
        backtrack(0, nums, current, subsets);
        return subsets;
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for(auto sub : getSubsets(nums)) {
            int curr = 0;
            for(int num : sub)
                curr ^= num;
            sum += curr;
        }
        return sum;
    }
};