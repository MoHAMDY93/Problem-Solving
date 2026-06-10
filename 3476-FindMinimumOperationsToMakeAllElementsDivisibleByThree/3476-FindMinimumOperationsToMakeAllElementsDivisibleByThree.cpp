// Last updated: 6/10/2026, 7:13:35 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i : nums) ans += min(i % 3 , 3 - (i%3));
        return ans;
    }
};