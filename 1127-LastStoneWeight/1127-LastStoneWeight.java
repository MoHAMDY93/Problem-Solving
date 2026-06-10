// Last updated: 6/10/2026, 7:22:28 PM
/*
 * @lc app=leetcode id=1046 lang=java
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
import java.util.*;
class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> pq = new PriorityQueue<>((a , b) -> b - a);
        for (int i : stones) pq.add(i);
        while (pq.size() > 1) {
            int a = pq.remove() , b = pq.remove();
            // System.out.printf(a + " " + b + "\n");
            if (a == b) continue;
            else pq.add(Math.abs(a - b));
        }
        return pq.size() == 0 ? 0 : pq.peek();
    }
}
// @lc code=end

