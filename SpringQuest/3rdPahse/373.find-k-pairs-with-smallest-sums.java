/*
 * @lc app=leetcode id=373 lang=java
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
import java.util.*;
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        Queue<List<Integer>> pq = new PriorityQueue<>((a , b) -> Integer.compare(a.get(0), b.get(0)));
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums1.length , m = nums2.length;
        for (int i=0 ; i<n ; i++) pq.add(Arrays.asList(nums1[i] + nums2[0] , i , 0));
        while (k-- > 0) {
            var tmp = pq.poll();
            int i = tmp.get(1) , j = tmp.get(2);
            ans.add(Arrays.asList(nums1[i] , nums2[j]));
            if (j+1 < m)
                pq.add(Arrays.asList(nums1[i] + nums2[j+1] , i , j+1));
        }
        return ans;
    }
}
// @lc code=end

