// Last updated: 6/10/2026, 7:24:13 PM
class Solution {
    public int[] findErrorNums(int[] nums) {
        Map<Integer , Integer> map = new HashMap<>();
        for(int i : nums) {
            map.put(i , map.merge(i , 1 , Integer::sum));
        }
        int dup = -1 , miss = -1;
        for(int i=1 ; i<=nums.length ; i++) {
            if(map.getOrDefault(i , 0) == 0) miss = i;
            else if(map.getOrDefault(i , 0) == 2) dup = i;
        }
        return new int[]{dup , miss};
    }
}