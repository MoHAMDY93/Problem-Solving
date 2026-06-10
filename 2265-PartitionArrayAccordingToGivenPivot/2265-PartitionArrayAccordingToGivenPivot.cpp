// Last updated: 6/10/2026, 7:17:47 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0 , right = n-1;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }
            if (nums[n-1-i] > pivot) {
                ans[right--] = nums[n-1-i];
            }
        }
        while (left <= right) {
            ans[left++] = pivot;
        }
        return ans;
    }
};