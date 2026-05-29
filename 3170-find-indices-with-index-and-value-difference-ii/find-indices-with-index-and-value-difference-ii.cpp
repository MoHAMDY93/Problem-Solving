class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<int> suff_min(n) , suff_max(n);
        suff_min[n-1] = suff_max[n-1] = n-1;
        for (int i = n-2; i >= 0; --i) {
            suff_min[i] = (nums[i] <= nums[suff_min[i+1]]) ? i : suff_min[i+1];
            suff_max[i] = (nums[i] >= nums[suff_max[i+1]]) ? i : suff_max[i+1];
        }
        for (int i=0 ; i<n ; i++) {
            if (i + indexDifference >= n) break;
            // cout << nums[suff_min[i + indexDifference]] << ' ' << nums[suff_max[i + indexDifference]] << '\n';
            // cout << abs(nums[i] - nums[suff_min[i + indexDifference]]) << ' ';
            // cout << abs(nums[i] - nums[suff_max[i + indexDifference]]) << '\n';
            if (abs(nums[i] - nums[suff_min[i + indexDifference]]) >= valueDifference) 
                return {i , suff_min[i + indexDifference]};
            if (abs(nums[i] - nums[suff_max[i + indexDifference]]) >= valueDifference) 
                return {i , suff_max[i + indexDifference]};
        }
        return {-1 , -1};
    }
};