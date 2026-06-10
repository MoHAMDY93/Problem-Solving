// Last updated: 6/10/2026, 7:10:28 PM
class Solution {
    static class Pair {
        char first;
        int second;

        Pair(char f, int s) {
            first = f;
            second = s;
        }
    }
    public String removeSubstring(String s, int k) {
        List<Pair> st = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (!st.isEmpty() && st.get(st.size() - 1).first == c) {
                // Same character, increment count
                st.get(st.size() - 1).second++;
            } else {
                // Different character, push new entry
                st.add(new Pair(c, 1));
            }
            int n = st.size();
            if(n >= 2 && st.get(n-2).first == '(' && st.get(n-2).second >= k 
                && st.get(n-1).first == ')' && st.get(n-1).second == k) {
                
                st.remove(n - 1);
                st.get(n-2).second -= k;
                if(st.get(n-2).second == 0) st.remove(n-2);
            }
        }

        // Reconstruct the string
        StringBuilder result = new StringBuilder();
        for (Pair p : st) {
            for (int i = 0; i < p.second; i++) {
                result.append(p.first);
            }
        }
        return result.toString();
    }
}