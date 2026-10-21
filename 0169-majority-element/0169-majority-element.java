class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i : nums) {
            freq.put(i , freq.getOrDefault(i , 0) + 1);
            if (freq.get(i) > nums.length / 2) return i;
        }
        return 0;
    }
}