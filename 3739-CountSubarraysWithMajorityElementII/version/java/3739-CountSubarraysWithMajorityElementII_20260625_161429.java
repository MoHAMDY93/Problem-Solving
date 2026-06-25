// Last updated: 6/25/2026, 4:14:29 PM
// This is the most briliant idea i ever got in this problem
1class Solution {
2    public long countMajoritySubarrays(int[] nums, int target) {
3        int n = nums.length;
4        int[] freq = new int[2*n + 1];
5        Arrays.fill(freq , 0);
6        freq[n] = 1;
7        int curr = 0;
8        long less_count = 0;
9        long ans = 0;
10        for (int i=0 ; i<n ; i++) {
11            int delta = (nums[i] == target ? +1 : -1);
12            if (delta == 1) {
13                less_count += freq[curr + n];
14                curr++;
15            } else {
16                curr--;
17                less_count -=freq[curr + n];
18            }
19            freq[curr + n]++;
20            ans += less_count;
21        }
22        return ans;
23    }
24}