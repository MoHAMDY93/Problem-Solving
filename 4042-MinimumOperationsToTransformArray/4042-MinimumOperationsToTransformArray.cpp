// Last updated: 6/10/2026, 7:10:19 PM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        int v = nums2.back();
        int last = 1e9;
        for(int i=0 ; i<n ; i++) {
            ans += abs(nums1[i] - nums2[i]);
            if((nums1[i] <= v && v <= nums2[i]) || (nums2[i] <= v && v <= nums1[i])) {
                last = 0;
            } else {
                last = min({last , abs(nums1[i] - v) , abs(nums2[i] - v)});
            }
        }
        return ans + last + 1;
    }
};