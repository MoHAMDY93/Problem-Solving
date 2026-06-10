// Last updated: 6/10/2026, 7:13:09 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums) {
            int b = 0;
            if((n & 1) == 0) ans.push_back(-1);
            else {  
                int cnt = 0 , tmp = n;
                while(n & 1) cnt++ , n >>= 1;
                ans.push_back(tmp - (1 << (cnt-1)));  
            }
        }
        return ans;
    }
};