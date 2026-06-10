// Last updated: 6/10/2026, 7:09:05 PM
class Solution {
public:
    long long MOD = (long long)(1e9 + 7);
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefSum(n+1 , 0) , prefX(n+1 , 0) , pow10(n+1 , 1) , nonZCnt(n+1 , 0);
        for(int i=1 ; i<=n ; i++) pow10[i] = (pow10[i-1] * 10) % MOD;
        long long curr = 0 , cnt = 0;
        for(int i=0 ; i<n ; i++) {
            int d = s[i] - '0';
            prefSum[i+1] = prefSum[i] + d;
            if(d != 0) {
                curr = (curr * 10 + d) % MOD;
                nonZCnt[i+1] = 1 + nonZCnt[i];
             } else 
                nonZCnt[i+1] = nonZCnt[i];

            prefX[i+1] = curr;
        }
        vector<int> ans;
        for(auto q : queries) {
            int l = q[0] , r = q[1];
            long long sum = prefSum[r+1] - prefSum[l];
            if(sum == 0 || nonZCnt[r+1] == nonZCnt[l]) { ans.push_back(0); continue; };
            long long left = prefX[l];
            int cnt = nonZCnt[r+1] - nonZCnt[l];
            long long X = (prefX[r+1] - (prefX[l] * pow10[cnt]) % MOD + MOD) % MOD;
            ans.push_back((X * sum) % MOD);
        }
        return ans;
    }
};