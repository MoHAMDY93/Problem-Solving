// Last updated: 6/10/2026, 7:11:28 PM
class Solution {
    static class node {
        int u , w; 
        public node(int u , int w) {
            this.u = u;
            this.w = w;
        }
    }
    public int minCost(int n, int[][] edges) {
        List<List<node>> adj = new ArrayList<>();
        for(int i=0 ; i<n ; i++) adj.add(new ArrayList<>());
        for(var e : edges) {
            int u = e[0] , v = e[1] , w = e[2];
            adj.get(u).add(new node(v , w));
            adj.get(v).add(new node(u , 2 * w));
        }
        PriorityQueue<node> pq = new PriorityQueue<>((a , b) -> a.w - b.w);
        List<Integer> dist = new ArrayList<>(Collections.nCopies(n, Integer.MAX_VALUE));
        
        pq.add(new node(0 , 0));
        dist.set(0 , 0);
        while(pq.size() > 0) {
            node curr = pq.poll();
            if(curr.w > dist.get(curr.u)) continue;
            for(var v : adj.get(curr.u)) {
                if(curr.w + v.w < dist.get(v.u)) {
                    pq.add(new node(v.u , curr.w + v.w));
                    dist.set(v.u , curr.w + v.w);
                }
            }
        }
        return dist.get(n-1) == Integer.MAX_VALUE ? -1 : dist.get(n-1);
    }
}