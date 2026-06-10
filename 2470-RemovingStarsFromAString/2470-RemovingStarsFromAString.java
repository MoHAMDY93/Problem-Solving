// Last updated: 6/10/2026, 7:16:56 PM
class Solution {
    public String removeStars(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '*' && sb.length() > 0) sb.deleteCharAt(sb.length() - 1);
            else if (c != '*') sb.append(c);
        }
        return sb.toString();
    }
}