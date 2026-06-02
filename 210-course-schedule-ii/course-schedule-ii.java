class Solution {
    public int[] findOrder(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>(n);
        int[] indeg = new int[n];
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        Arrays.fill(indeg , 0);
        for (var e : edges) {
            adj.get(e[1]).add(e[0]);
            indeg[e[0]]++;
        } 
        Deque<Integer> q = new ArrayDeque<>();
        for (int u=0 ; u<n ; u++) {
            if (indeg[u] == 0) q.addLast(u);
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int u = q.removeFirst();
            ans.add(u);
            for (int v : adj.get(u)) {
                indeg[v]--;
                if (indeg[v] == 0) q.addLast(v);
            }
        }
        if (ans.size() != n) return new int[0];
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ans.get(i);
        }
        return res;
    }
}