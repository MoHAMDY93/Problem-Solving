// Last updated: 6/10/2026, 7:17:50 PM
class Solution {
private:
    long long dp[100001];
    long long solve(int i , vector<vector<int>>& questions , int n) {
        if(i >= n) 
            return 0;
        if(dp[i]) 
            return dp[i];
        return dp[i] = max(solve(i + 1 , questions , n) , solve(i+1+questions[i][1] , questions , n) + questions[i][0]);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {  
        int n = questions.size();
        return solve(0 , questions , n);
    }
};