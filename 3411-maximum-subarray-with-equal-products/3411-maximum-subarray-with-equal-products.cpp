class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int l=0 ; l<n ; l++) {
            int p = 1, gc = 0, lc = 1;
            for (int r = l ; r<n ; r++) {
                p *= nums[r];
                gc = gcd(gc, nums[r]);
                lc = lcm(lc, nums[r]);
                if (p > gc * lc) break;
                // cout << p << ' ' << gc << ' ' << lc << '\n';
                ans = max(ans, r-l+1);
            }
            // cout << "--------------\n"; 
        }
        return ans;
    }
};