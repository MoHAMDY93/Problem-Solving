/*
 * @lc app=leetcode id=207 lang=java
 *
 * [207] Course Schedule
 */

// @lc code=start
import java.util.*;
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        List<List<Integer>> adj = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indeg = new int[n];
        Arrays.fill(indeg , 0);
        for (var cond : prerequisites) {
            int u = cond[0] , v = cond[1];
            adj.get(u).add(v);
            indeg[v]++;
        } 
        Deque<Integer> q = new ArrayDeque<>();
        for (int i=0 ; i<n ; i++) {
            if (indeg[i] == 0) q.add(i);
        }
        int taken = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            taken++;
            for (int v : adj.get(u)) {
                indeg[v]--;
                if (indeg[v] == 0) 
                    q.add(v);
            }
        }

        return taken == n;
    }
}
// @lc code=end

