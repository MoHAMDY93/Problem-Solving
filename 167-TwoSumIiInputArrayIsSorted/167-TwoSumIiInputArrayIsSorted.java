// Last updated: 6/10/2026, 7:26:10 PM
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l=0 , r = numbers.length-1;
        while (l < r) {
            int curr = numbers[l] + numbers[r];
            if(curr == target) return new int[]{l+1 , r+1};
            if(curr < target) l++;
            if(curr > target) r--; 
        }
        return new int[]{};
    }
}