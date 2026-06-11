// Last updated: 6/11/2026, 5:02:44 AM
1class Solution {
2    static final int MOD = 1_000_000_007;
3    private List<List<Integer>> adj;
4    private int dfs(int u , int p) {
5        int len = 0;
6        for (int v : adj.get(u)) {
7            if (v == p) continue;
8            len = Math.max(len , 1 + dfs(v , u));
9        }
10        return len;
11    }
12    static int binPow(int pow) {
13        long res = 1 , base = 2;
14        while (pow > 0) {
15            if ((pow & 1) == 1) res = res * base % MOD;
16            base = base * base % MOD;
17            pow >>= 1;
18        }
19        return (int)res;
20    }
21    public int assignEdgeWeights(int[][] edges) {
22        int n = edges.length+1;
23        adj = new ArrayList<>(n+1);
24        for (int i=0 ; i<=n ; i++) {
25            adj.add(new ArrayList<>());
26        }
27        for (var v : edges) {
28            adj.get(v[0]).add(v[1]);
29            adj.get(v[1]).add(v[0]);
30        }
31        int maxi = dfs(1 , 0);
32        return binPow(maxi-1);
33    }
34}