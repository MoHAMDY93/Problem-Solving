// Last updated: 6/10/2026, 7:14:49 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long MAX = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                for(int k = j+1 ; k<n ; k++) {
                    MAX = max(MAX, (1LL * (nums[i] - nums[j]) * nums[k]));
                }
            }
        }
        return MAX;
    }
};