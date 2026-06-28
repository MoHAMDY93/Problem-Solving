// Last updated: 6/28/2026, 6:19:35 AM
1class Solution {
2public:
3    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
4        vector<vector<pair<int , int>>> adj(n);
5        for (auto e : edges) {
6            int u = e[0] , v = e[1] , w = e[2];
7            adj[u].push_back({v , w});
8        }
9        vector<vector<long long>> dist(n , vector<long long>(power+1 , LLONG_MAX));
10        auto comp = [&](auto& a, auto& b) {
11            if (a[1] != b[1]) return a[1] > b[1];
12            return a[2] < b[2];
13        };
14        priority_queue<array<long long, 3>, vector<array<long long, 3>>, decltype(comp)> pq(comp);
15        dist[source][power] = 0;
16        pq.push({source , 0 , power});
17        while (!pq.empty()) {
18            auto curr = pq.top(); pq.pop();
19            auto [u , time , rem] = curr;
20            if (time > dist[u][rem]) continue;
21            if (u == target) {
22                return {time , rem};
23            }
24            if (rem < cost[u]) continue;
25            for (auto [v , w] : adj[u]) {
26                if (dist[v][rem - cost[u]] > time + w) {
27                    dist[v][rem - cost[u]] = time + w;
28                    pq.push({v , time + w , rem - cost[u]});
29                }
30            }
31        }
32        return {-1 , -1};
33    }
34};