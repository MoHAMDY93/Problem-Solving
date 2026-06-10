// Last updated: 6/10/2026, 7:15:59 PM
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int MOD = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        int num = types.size();
        for(int i = 0; i < num; i++){
            int cnt = types[i][0];
            int marks = types[i][1];
            for(int j = target; j >= 1; j--){
                for(int k = 1; k <= cnt; k++){
                    int total = k * marks;
                    if(j >= total){
                        dp[j] = (dp[j] + dp[j - total]) % MOD;
                    }else{
                        break;
                    }
                }
            }
        }
        return dp[target];
    }
};