class Solution {
    public int majorityElement(int[] nums) {
        int cand = 0 , cnt = 0;
        for (int i : nums) {
            if (cnt == 0) cand = i;
            cnt += (i == cand ? +1 : -1);
        }
        return cand;
    }
}