// Last updated: 6/21/2026, 12:57:50 PM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin() , costs.end());
5        int cnt = 0;
6        for (int i=0 ; i<costs.size() ; i++) {
7            if (costs[i] > coins) break;
8            cnt++ , coins -= costs[i];
9        }
10        return cnt;
11    }
12};