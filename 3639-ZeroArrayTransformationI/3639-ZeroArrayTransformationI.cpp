// Last updated: 6/10/2026, 7:12:56 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>a(n+1 , 0);
        for(auto q : queries) {
            int l = q[0] , r = q[1];
            a[l]++ , a[r+1]--;
        }
        long long sum = a[0];
        for(int i=0 ; i<n ; i++) {
            if(sum < nums[i])
                return false;
            sum += a[i+1];
        }
        return true;
    }
};