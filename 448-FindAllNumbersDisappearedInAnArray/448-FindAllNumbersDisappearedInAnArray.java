// Last updated: 6/10/2026, 7:24:51 PM
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        Set<Integer> st = new HashSet<>();
        for(int i : nums) st.add(i);
        List<Integer> ans = new ArrayList<>();
        for(int i=1 ; i<=nums.length ; i++) {
            if(!st.contains(i)) ans.add(i);
        }   
        return ans;
    }
}