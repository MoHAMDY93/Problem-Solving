// Last updated: 6/10/2026, 7:12:47 PM
using ll = long long;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {
        ll sum = 0;
        ll subMax = LLONG_MIN;
        vector<ll> minSoFar(k , LLONG_MAX / 2);
        minSoFar[(k-1) % k] = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            sum += nums[i];
            subMax = max(subMax , sum - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k] , sum);
        }
        return subMax;
    }
};