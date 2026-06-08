class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int cnt1 = 0 , cnt2 = n-1;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] < pivot) ans[cnt1++] = nums[i];
        }
        for (int i=n-1 ; i>=0 ; i--) {
            if (nums[i] > pivot) ans[cnt2--] = nums[i];
        }
        for (int i=0 ; i<n ; i++) {
            if (nums[i] == pivot) ans[cnt1++] = nums[i];
        }
        return ans;
    }
};