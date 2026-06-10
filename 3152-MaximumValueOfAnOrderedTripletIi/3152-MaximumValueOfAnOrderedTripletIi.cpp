// Last updated: 6/10/2026, 7:14:50 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long A = 0 , A_B = 0 , ans = 0;
        for(int num : nums) {
            ans = max(ans , A_B * num);
            A_B = max(A_B , A - num);
            A = max(A , 1LL * num);
        }
        return ans;
    }
};