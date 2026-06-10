// Last updated: 6/10/2026, 7:15:38 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(auto i : nums) cnt += (i == 1);
        if(cnt) return n - cnt; 
        int mn = INT_MAX;
        for(int i=0 ; i<n ; i++) {
            int gc = 0;
            for(int j=i ; j<n ; j++) {
                gc = gcd(gc , nums[j]);
                if(gc == 1) mn = min(mn , j - i + n-1);
            }
        }
        return (mn == INT_MAX ? -1 : mn);
    }
};