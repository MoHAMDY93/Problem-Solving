// Last updated: 6/10/2026, 7:25:23 PM
class Solution {
    public int nthUglyNumber(int n) {
        TreeSet<Long> set = new TreeSet<>();
        set.add(1L);
        for(int i=1 ; i<n ; i++) {
            Long curr = set.pollFirst();
            set.addAll(Arrays.asList(curr*2 , curr*3 , curr*5));
        }
        for(var i : set) System.out.println(i);
        return set.first().intValue();
    }
}