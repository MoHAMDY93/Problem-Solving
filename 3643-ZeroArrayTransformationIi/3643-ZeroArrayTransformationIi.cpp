// Last updated: 6/10/2026, 7:12:53 PM
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        /*
            binary sercah on the k
            and for each possible k in the searching we create a diff array of the first k queries
            then we check for each element in the array if its value is greater than the diff value 
            O(n logn) 
        */
        int n = nums.size() , m = queries.size();
        auto check = [&](int k) -> bool {
            vector<int> delta(n+2 , 0);
            for (int i=0 ; i<k ; i++) {
                int l = queries[i][0] , r = queries[i][1] , val = queries[i][2];
                delta[l] += val;
                delta[r+1] -= val;
            }
            for (int i=1 ; i<n+2 ; i++) delta[i] += delta[i-1];
            for (int i=0 ; i<n ; i++) if (nums[i] > delta[i]) return false;
            return true;
        };
        int lo = 0 , hi = m , ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) ans = mid , hi = mid-1;
            else lo = mid+1;
        }
        return ans;
    }
};