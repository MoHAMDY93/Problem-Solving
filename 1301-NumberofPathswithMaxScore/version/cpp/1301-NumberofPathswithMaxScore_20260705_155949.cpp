// Last updated: 7/5/2026, 3:59:49 PM
// Back to 2D Dpppppp
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    vector<int> pathsWithMaxScore(vector<string>& board) {
5        int n = board.size();
6        vector<vector<int>> score(n , vector<int> (n , -1));
7        vector<vector<int>> ways(n , vector<int> (n , 0));
8        score[n-1][n-1] = 0;
9        ways[n-1][n-1] = 1;
10        for (int i=n-1 ; i>=0 ; i--) {
11            for (int j = n-1 ; j>=0 ; j--) {
12                long long best = -1 , cnt = 0;
13                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
14                if (i+1 < n && score[i+1][j] > best) best = score[i+1][j];
15                if (j+1 < n && score[i][j+1] > best) best = score[i][j+1];
16                if (i+1 < n && j + 1 < n && score[i+1][j+1] > best) best = score[i+1][j+1];
17                if (best == -1) continue;
18                if (i+1 < n && score[i+1][j] == best) cnt = (cnt + ways[i+1][j]) % MOD; 
19                if (j+1 < n && score[i][j+1] == best) cnt = (cnt + ways[i][j+1]) % MOD; 
20                if (i+1 < n && j+1 < n && score[i+1][j+1] == best) cnt = (cnt + ways[i+1][j+1]) % MOD;
21
22                score[i][j] = best;
23                if ('0' <= board[i][j] && board[i][j] <= '9') score[i][j] += board[i][j] - '0';
24                ways[i][j] = cnt; 
25            }
26        }
27        if (ways[0][0] == 0) return {0 , 0};
28        return {score[0][0] , ways[0][0]};
29    }
30};