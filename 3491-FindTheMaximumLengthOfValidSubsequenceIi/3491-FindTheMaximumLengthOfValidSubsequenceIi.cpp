// Last updated: 6/10/2026, 7:13:28 PM
const int N = 1e3+5;
class Solution {
public:
    int dp[N][N];
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0 ; i<n-1 ; i++) { // teh first ellement in the seq;
            for(int j = i+1 ; j<n ; j++) { // the 2nd one
                int curr = (nums[i] + nums[j]) % k;
                if(dp[j][curr]) ans = max(ans , dp[j][curr]);
                else {
                    int L = j , R = j+1 , cnt = 2;
                    while(R < n) {
                        if((nums[L] + nums[R]) % k == curr) cnt++ , L = R;
                        R++;
                    } 
                    dp[j][curr] = cnt;
                    ans = max(ans , cnt);
                }
            }
        }
        return ans;
    }
};