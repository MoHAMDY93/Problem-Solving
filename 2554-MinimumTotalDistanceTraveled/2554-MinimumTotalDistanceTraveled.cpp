// Last updated: 6/10/2026, 7:16:26 PM
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> fp;
        for (auto v : factory) {
            for (int i=0 ; i<v[1] ; i++) fp.push_back(v[0]);
        }
        sort(fp.begin() , fp.end());
        sort(robot.begin() , robot.end());
        int n = robot.size() , m = fp.size();
        vector<vector<long long>> dp(n+1 , vector<long long>(m+1 , LLONG_MAX / 4));
        for (int i=0 ; i<=m ; i++) dp[n][i] = 0;
        for (int i=n-1 ; i>=0 ; i--) {
            for (int j=m-1 ; j>=0 ; j--) {
                dp[i][j] = min(dp[i][j+1] , dp[i+1][j+1] + abs(robot[i] - fp[j]));
            }
        }

        return dp[0][0];
    }
};