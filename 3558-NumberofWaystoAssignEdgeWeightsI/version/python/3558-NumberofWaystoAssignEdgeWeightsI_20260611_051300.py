# Last updated: 6/11/2026, 5:13:00 AM
1class Solution:
2    MOD = 10**9 + 7
3    def dfs(self , u , p, adj):
4        mx = 0
5        for v in adj[u]:
6            if (v == p):
7                continue
8            mx = max(mx , 1 + self.dfs(v , u , adj))
9        return mx
10    def bin_pow(self , exp):
11        res , base = 1 , 2
12        MOD = self.MOD
13        while exp > 0:
14            if exp & 1:
15                res = (res * base) % MOD
16            base = (base * base) % MOD
17            exp >>= 1
18        return res
19    
20    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
21        n = len(edges) + 1
22        adj = [[] for _ in range (n+1)]
23        for u , v in edges:
24            adj[u].append(v)
25            adj[v].append(u)
26        
27        maxi = self.dfs(1 , 0, adj)
28        return self.bin_pow(maxi - 1)