// Last updated: 6/21/2026, 1:22:09 AM
1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        restrictions.push_back({1 , 0});
5        sort(restrictions.begin() , restrictions.end());
6        if (restrictions.back()[0] != n)
7            restrictions.push_back({n , n-1});
8        int m = restrictions.size();
9        
10        for (int i=1 ; i<m ; i++) {
11            int id_prev = restrictions[i-1][0]; 
12            int h_prev = restrictions[i-1][1];
13            int id_curr = restrictions[i][0]; 
14            int h_curr = restrictions[i][1];
15            restrictions[i][1] = min(h_curr , h_prev + (id_curr - id_prev));
16        }
17        for (int i=m-2 ; i>=0 ; i--) {
18            int id_prev = restrictions[i+1][0]; 
19            int h_prev = restrictions[i+1][1];
20            int id_curr = restrictions[i][0]; 
21            int h_curr = restrictions[i][1];
22            restrictions[i][1] = min(h_curr , h_prev + (id_prev - id_curr));
23        }
24        int ans = 0;
25        for (int i=0 ; i+1<m ; i++) {
26            int id_prev = restrictions[i+1][0]; 
27            int h_prev = restrictions[i+1][1];
28            int id_curr = restrictions[i][0]; 
29            int h_curr = restrictions[i][1];
30
31            ans = max(ans , (h_curr + h_prev + (id_prev - id_curr)) / 2);
32        }
33        return ans;
34    }
35};