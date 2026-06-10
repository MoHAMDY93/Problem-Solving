// Last updated: 6/10/2026, 7:08:02 PM
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n+1 , 0);
        for (int i=0 ; i<n ; i++) pref[i+1] = pref[i] + (nums[i] % 2 == 0 ? 1 : 0);
        vector<int> ans;
        for (auto q : queries) {
            long long l = q[0] , r = q[1] , k = q[2];
            long long lo = 1 , hi = 3e9 , res = 3e9;
            while (lo <= hi) {
                long long mid = lo + (hi - lo) / 2;
                long long target = (mid > 2e9 ? 2e9 + 1 : mid);
                long long idx = upper_bound(nums.begin() , nums.end() , target) - nums.begin() - 1;
                long long rr = min(r , idx);
                long long rem = 0;
                if (rr >= l) rem = pref[rr+1] - pref[l];
                long long evens = mid / 2 - rem;
                if (evens >= k) res = mid , hi = mid-1;
                else lo = mid+1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};