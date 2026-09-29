class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> memo(n , vector<vector<int>> (m , vector<int> (n + m , -1)));
        auto dp = [&](this auto&& dp , int i , int j , int open) -> int {
            if (i == n-1 && j == m-1) return (open == 0);
            int rem = n + m - i - j - 1;
            if (open > rem) return 0;
            auto& ret = memo[i][j][open];
            if (~ret) return ret;
            ret = 0;
            if (i+1 < n && (grid[i+1][j] == '(' || (grid[i+1][j] == ')' && open > 0))) 
                ret = max(ret , dp(i+1 , j , open + (grid[i+1][j] == '(' ? +1 : -1)));
                
            if (j+1 < m && (grid[i][j+1] == '(' || (grid[i][j+1] == ')' && open > 0))) 
                ret = max(ret , dp(i , j+1 , open + (grid[i][j+1] == '(' ? +1 : -1)));

            return ret;
        };
        if (grid[0][0] == ')' || grid[n-1][m-1] == '(' || (n + m - 1) & 1) return false;
        return dp(0 , 0 , 1);
    }
};