// Last updated: 6/10/2026, 7:25:27 PM
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int r = 0; r < nums.length; r++) {
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[r]) dq.pollLast();
            dq.addLast(r);
            if (dq.peekFirst() <= r - k) dq.pollFirst();
            if (r >= k - 1) res[r - k + 1] = nums[dq.peekFirst()];
        }
        return res;
    }
}