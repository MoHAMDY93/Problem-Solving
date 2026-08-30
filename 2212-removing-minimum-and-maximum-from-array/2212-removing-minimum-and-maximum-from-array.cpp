class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = *min_element(nums.begin() , nums.end());
        int mx = *max_element(nums.begin() , nums.end());
        if (mn == mx) return 1;
        int left_mn = 1 , right_mn = 1 , dir_mn = 0;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] == mn) dir_mn = 1;
            else (dir_mn ? right_mn : left_mn)++;
        }
        int left_mx = 1 , right_mx = 1 , dir_mx = 0;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] == mx) dir_mx = 1;
            else (dir_mx ? right_mx : left_mx)++;
        }
        // cout << left_mn << ' ' << right_mn << '\n' << left_mx << ' ' << right_mx << '\n';
        int ans = min({
            max(left_mn , left_mx) , 
            max(right_mn , right_mx) , 
            left_mn + right_mx ,
            right_mn + left_mx
        });
        // if (left_mn <= right_mn && left_mx <= right_mx) ans = max(left_mn , left_mx);
        // else if (left_mn > right_mn && left_mx > right_mx) ans = max(right_mn , right_mx);
        // else ans = min(left_mn , right_mn) + min(left_mx , right_mx);
        return ans;
    }
};