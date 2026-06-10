// Last updated: 6/10/2026, 7:19:02 PM
class Solution {
    private static final int INF = Integer.MAX_VALUE / 2;
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        List<List<int[]>> adj = new ArrayList<>();
        int n = passingFees.length;
        for(int i=0 ; i<n ; i++) adj.add(new ArrayList<>());
        for(int[] e : edges) {
            int u = e[0] , v = e[1] , w = e[2];
            // int cost = passingFees[v];
            adj.get(u).add(new int[]{v , w , passingFees[v]});
            adj.get(v).add(new int[]{u , w , passingFees[u]});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a , b) -> {
                if(a[0] != b[0])
                    return Integer.compare(a[0] , b[0]);
                return Integer.compare(a[1] , b[1]);
            }
        );
        int[] Cost = new int[n];
        int[] Time = new int[n];

        Arrays.fill(Cost , INF);
        Arrays.fill(Time , INF);
        
        pq.add(new int[]{passingFees[0] , 0 , 0});
        Cost[0] = passingFees[0];

        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int fees = curr[0] , time = curr[1] , u = curr[2];
            // if(tim > dist[u]) continue;
            for(int[] nxt : adj.get(u)) {
                if(time + nxt[1] <= maxTime) {
                    if(fees + nxt[2] < Cost[nxt[0]]) {
                        Cost[nxt[0]] = fees + nxt[2];
                        Time[nxt[0]] = time + nxt[1];
                        pq.add(new int[]{Cost[nxt[0]] , Time[nxt[0]] , nxt[0]});
                    } 
                    else if(time + nxt[1] < Time[nxt[0]]) {
                        Time[nxt[0]] = time + nxt[1];
                        pq.add(new int[]{fees + nxt[2] , Time[nxt[0]] , nxt[0]});
                    }
                }
            }
        } 

        return Cost[n-1] >= INF ? -1 : Cost[n-1];
    }
}