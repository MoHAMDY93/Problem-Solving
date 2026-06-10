// Last updated: 6/10/2026, 7:18:20 PM
import java.util.*;
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length , ans = 0;
        // simulation
        Deque<Integer> queue = new LinkedList<>();
        for (int i =0 ; i<n ; i++) queue.add(i);
        while (tickets[k] > 0) {
            tickets[queue.peek()]--;
            if (tickets[queue.peek()] == 0) queue.remove();
            else queue.add(queue.remove());
            ans++;
        }
        return ans;
        // // optimization in O(n)
        // for (int i=0 ; i<n ; i++) {
        //     if (i <= k) ans += Math.min(tickets[i], tickets[k]);
        //     else ans += Math.min(tickets[k]-1, tickets[i]);
        // }
        // return ans;
    }
}