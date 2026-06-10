// Last updated: 6/10/2026, 7:25:48 PM
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> st = new HashSet<>();
        while (true) {
            if (n == 1) return true;
            if (st.contains(n)) return false;
            st.add(n);
            int sum = 0;
            while (n > 0) {
                sum += Math.pow(n % 10 , 2);
                n /= 10;
            }
            n = sum;
        }
    }
}