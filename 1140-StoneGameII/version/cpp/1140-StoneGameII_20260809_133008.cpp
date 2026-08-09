// Last updated: 8/9/2026, 1:30:08 PM
1class Solution {
2private: 
3    vector<vector<int>> memo; 
4    int getScore(vector<int> &piles, int pos, int m) {
5        if(pos == piles.size()) return 0; // noscore 
6        if(memo[pos][m] != -1) return memo[pos][m]; 
7        int cur = 0; 
8        int best = INT_MIN; 
9        for(int i = pos; i < piles.size() && i < pos + 2 * m; i++) {
10            cur += piles[i]; 
11            best = max(best, cur - getScore(piles, i + 1, max(m, i - pos + 1))); 
12        }
13
14        return memo[pos][m] = best; 
15    }
16public:
17    int stoneGameII(vector<int>& piles) {
18        // find the net optimal difference 
19        // a + b = piles.sum 
20        // a- b = nedDiff 
21        // a = (piles.sum + netDiff) / 2 
22        memo = vector<vector<int>>(piles.size(), vector<int>(100, -1)); 
23    
24        int netDiff = getScore(piles, 0, 1); 
25        int sum = 0; 
26        for(int x: piles) sum+= x; 
27        int a = (netDiff + sum) / 2; 
28        return a;
29    }
30};