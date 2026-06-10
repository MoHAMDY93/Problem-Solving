// Last updated: 6/10/2026, 7:18:50 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0 , mn = INT_MAX;
        long long sum = 0;
        for(auto r : matrix) for(auto c : r) { cnt += c < 0; sum += abs(c); mn = min(mn , abs(c)); }
        if(cnt & 1) return sum - 2*mn;
        return sum;
    }
};