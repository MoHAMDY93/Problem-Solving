// Last updated: 6/10/2026, 7:09:55 PM
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        // try all the possibilties using dp ??
        // each posisiton can either has i or 
        // we can use greedy approach
        long long sum = 1ll * n * (n+1) / 2;
        if(abs(target) > sum || (sum - target) & 1) return {};
        long long neg = (sum - target) / 2;
        vector<int> ans;
        unordered_set<int> st;
        for(int i=n ; i>=1 ; i--) if(neg >= i) st.insert(i) , neg-=i;
        for(int i=n ; i>=1 ; i--) if(st.count(i)) ans.push_back(-i);
        for(int i=1 ; i<=n ; i++) if(!st.count(i)) ans.push_back(i);
        return ans;
    }
};