// Last updated: 7/4/2026, 12:50:18 AM
1class Solution {
2public:
3    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
4        int n = online.size();
5
6        vector<vector<pair<int,int>>> graph(n);
7        vector<int> indegree(n, 0);
8
9        for (auto &e : edges) {
10            graph[e[0]].push_back({e[1], e[2]});
11            indegree[e[1]]++;
12        }
13
14        queue<int> q;
15        for (int i = 0; i < n; i++)
16            if (indegree[i] == 0)
17                q.push(i);
18
19        vector<int> topo;
20        while (!q.empty()) {
21            int u = q.front();
22            q.pop();
23            topo.push_back(u);
24
25            for (auto &[v, w] : graph[u]) {
26                if (--indegree[v] == 0)
27                    q.push(v);
28            }
29        }
30
31        auto check = [&](int limit) {
32            const long long INF = (1LL << 60);
33
34            vector<long long> dp(n, INF);
35            dp[0] = 0;
36
37            for (int u : topo) {
38
39                if (dp[u] == INF)
40                    continue;
41
42                if (u != 0 && u != n - 1 && !online[u])
43                    continue;
44
45                for (auto &[v, w] : graph[u]) {
46
47                    if (w < limit)
48                        continue;
49
50                    if (v != n - 1 && !online[v])
51                        continue;
52
53                    if (dp[u] + w < dp[v])
54                        dp[v] = dp[u] + w;
55                }
56            }
57
58            return dp[n - 1] <= k;
59        };
60
61        int left = 0, right = 1000000000;
62        int ans = -1;
63
64        while (left <= right) {
65            int mid = left + (right - left) / 2;
66
67            if (check(mid)) {
68                ans = mid;
69                left = mid + 1;
70            } else {
71                right = mid - 1;
72            }
73        }
74
75        return ans;
76    }
77};