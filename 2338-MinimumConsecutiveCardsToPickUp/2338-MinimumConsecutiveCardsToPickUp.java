// Last updated: 6/10/2026, 7:17:22 PM
class Solution {
    public int minimumCardPickup(int[] cards) {
        Map<Integer , Integer> mp = new HashMap<>();
        int n = cards.length;
        int res = Integer.MAX_VALUE;
        for (int i=0 ; i<n ; i++) {
            if (mp.containsKey(cards[i])) res = Math.min(res , i - mp.get(cards[i]) + 1);
            mp.put(cards[i] , i);
        }
        if(res == Integer.MAX_VALUE) return -1;
        return res;
    }
}