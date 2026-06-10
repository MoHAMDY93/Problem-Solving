// Last updated: 6/10/2026, 7:12:21 PM
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for(auto &v : grid) {
            sort(v.rbegin() , v.rend());
        }
        int n = grid.size();
        vector<int> a;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<limits[i] ; j++) a.push_back(grid[i][j]);
        }
        sort(a.rbegin() , a.rend());
        long long sum = 0;
        for(int i=0 ; i<k ; i++) sum += a[i];
        return sum;
    }
};