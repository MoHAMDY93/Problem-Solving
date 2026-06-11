class Solution {
    static final int MOD = 1_000_000_007;
    private List<List<Integer>> adj;
    private int dfs(int u , int p) {
        int len = 0;
        for (int v : adj.get(u)) {
            if (v == p) continue;
            len = Math.max(len , 1 + dfs(v , u));
        }
        return len;
    }
    static int binPow(int pow) {
        long res = 1 , base = 2;
        while (pow > 0) {
            if ((pow & 1) == 1) res = res * base % MOD;
            base = base * base % MOD;
            pow >>= 1;
        }
        return (int)res;
    }
    public int assignEdgeWeights(int[][] edges) {
        int n = edges.length+1;
        adj = new ArrayList<>(n+1);
        for (int i=0 ; i<=n ; i++) {
            adj.add(new ArrayList<>());
        }
        for (var v : edges) {
            adj.get(v[0]).add(v[1]);
            adj.get(v[1]).add(v[0]);
        }
        int maxi = dfs(1 , 0);
        return binPow(maxi-1);
    }
}