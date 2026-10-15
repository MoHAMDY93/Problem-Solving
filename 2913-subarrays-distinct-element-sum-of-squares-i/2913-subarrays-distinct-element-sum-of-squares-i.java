class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size() , ans = 0;
        for (int i=0 ; i<n ; i++) {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int j = i ; j<n ; j++) {
                cnt.merge(nums.get(j) , 1 , Integer::sum);
                ans += cnt.size() * cnt.size();
            } 
        }
        return ans;
    }
}