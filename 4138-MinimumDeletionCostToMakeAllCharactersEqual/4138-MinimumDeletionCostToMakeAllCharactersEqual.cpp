// Last updated: 6/10/2026, 7:08:56 PM
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = cost.size();
        vector<long long> a(26 , 0);
        long long sum = 0;
        for(int i=0 ; i<n ; i++) {
            sum += cost[i];
            a[s[i] - 'a'] += cost[i];
        }
        long long ans = LLONG_MAX;
        for(int i=0 ; i<26 ; i++) {
            // if(a[i] == 0) continue;
            ans = min(ans , sum - a[i]);
        }
        return ans;
    }
};