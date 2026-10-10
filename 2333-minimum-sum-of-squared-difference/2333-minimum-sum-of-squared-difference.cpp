class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int mx = 0;
        long long k = k1 + k2;
        // cout << k << '\n';
        // get the max difference to bound the freq array
        for (int i=0 ; i<n ; i++) 
            mx = max(mx , abs(nums1[i] - nums2[i]));
        
        vector<long long> freq(mx + 1 , 0);
        for (int i=0 ; i<n ; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
        }
        // now go from the max difference to the lower one
        // and try to lower the level to the next one
        for (int d = mx ; d > 0 ; d--) {
            if (freq[d] == 0) continue;
            int take = min(k , freq[d]);
            freq[d] -= take;
            freq[d-1] += take;
            k -= take;
        }
        long long ans = 0;
        for (long long d = mx ; d>0 ; d--) {
            ans += d * d * freq[d];
        }
        return ans;
    }
};