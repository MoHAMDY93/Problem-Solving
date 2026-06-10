// Last updated: 6/10/2026, 7:17:17 PM
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            long val = spells[i];
            int l = 0 , r = potions.length - 1 , idx = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                long tmp = val * potions[mid];
                if(tmp >= success) {
                    idx = mid;
                    r = mid-1;
                } else 
                    l = mid+1;
            }
            if(idx == -1) ans[i] = 0;
            else ans[i] = potions.length - idx;
        }
        return ans;
    }
}