// Last updated: 6/10/2026, 7:21:35 PM
class Solution {
public:
    int cntDigits(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            if(!(cntDigits(num) & 1))
                ans++;
        }
        return ans;
    }
};