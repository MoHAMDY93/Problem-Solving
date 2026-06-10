// Last updated: 6/10/2026, 7:27:14 PM
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int rem = digits[n-1] + 1 > 9 ? 1 : 0;
        digits[n-1] = (digits[n-1] + 1) % 10;
        for(int i = n-2 ; i>=0 ; i--) {
            int nr = digits[i] + rem > 9 ? 1 : 0;
            digits[i] = (digits[i] + rem) % 10;
            rem = nr;
        }
        if(rem == 1) {
            int[] ans = new int[n+1];
            ans[0] = 1;
            for(int i=0 ; i<n ; i++) ans[i+1] = digits[i];
            return ans;
        } else 
            return digits;
    }
}