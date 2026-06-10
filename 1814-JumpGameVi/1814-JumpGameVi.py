# Last updated: 6/10/2026, 7:19:51 PM
class Solution(object):
    def maxResult(self, nums, k):
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]

        dq = deque([0])  # store indices, front = max dp index

        for i in range(1, n):
            # The best dp for current i is at dq[0]
            dp[i] = nums[i] + dp[dq[0]]

            # Maintain decreasing deque (remove smaller dp values)
            while dq and dp[i] >= dp[dq[-1]]:
                dq.pop()
            dq.append(i)

            # Remove indices out of window [i-k, i-1]
            if dq[0] <= i - k:
                dq.popleft()

        return dp[-1]
