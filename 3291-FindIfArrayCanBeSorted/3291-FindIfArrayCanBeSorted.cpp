// Last updated: 6/10/2026, 7:14:17 PM
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int glob_min = INT_MAX , glob_max = INT_MIN;
        int curr_min = INT_MAX , curr_max = INT_MIN;
        int cnt = __builtin_popcount(nums[0]);
        for (int i=0 ; i<n ; i++) {
            int curr_cnt = __builtin_popcount(nums[i]);
            if (curr_cnt == cnt) curr_min = min(curr_min , nums[i]) , curr_max = max(curr_max , nums[i]);
            else {
                if (curr_min < glob_max) {
                    // cout << curr_min << ' ' << glob_max << endl;
                    return false;
                }
                cnt = curr_cnt;
                glob_min = min(glob_min , curr_min);
                glob_max = max(glob_max , curr_max);
                curr_min = nums[i];
                curr_max = nums[i];
            }
        }
        // cout << cnt << '\n';
        // cout << curr_min << ' ' << glob_max << endl;
        if (curr_min < glob_max) return false;
        return true;
    }
};