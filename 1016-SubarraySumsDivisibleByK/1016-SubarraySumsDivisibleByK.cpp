// Last updated: 6/10/2026, 7:22:52 PM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> m(k , 0);
        m[0] = 1;
        int pref = 0 , count = 0;
        for(auto i : nums) {
            pref += i;
            int mod = ((pref % k) + k) % k;
            count += m[mod];
            m[mod]++;
        }
        return count;
    }
};