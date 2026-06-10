// Last updated: 6/10/2026, 7:24:14 PM
import java.util.*;
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int ans[] = new int[n];
        Arrays.fill(ans , 0);

        Stack<Integer> stack = new Stack<>();
        int prev = 0;
        for(String log : logs) {
            String[] parts = log.split(":");
            int id = Integer.parseInt(parts[0]);
            int time = Integer.parseInt(parts[2]);
            String op = parts[1];

            if(op.equals("start")) {
                if(!stack.empty()) {
                    ans[stack.peek()] += time - prev;
                }
                stack.push(id);
                prev = time;
            } else {
                ans[stack.pop()] += time - prev + 1;
                prev = time+1;
            }
        }
        return ans;
    }
}