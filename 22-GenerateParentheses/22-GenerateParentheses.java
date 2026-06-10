// Last updated: 6/10/2026, 7:28:03 PM
class Solution {
    private void backtrack(List<String> res, StringBuilder cur, int open, int close, int n) {
        // Base case: string is complete
        if (cur.length() == 2 * n) {
            res.add(cur.toString());
            return;
        }

        // Try adding '(' if we still can
        if (open < n) {
            cur.append("(");
            backtrack(res, cur, open + 1, close, n);
            cur.deleteCharAt(cur.length() - 1); // backtrack
        }

        // Try adding ')' if valid
        if (close < open) {
            cur.append(")");
            backtrack(res, cur, open, close + 1, n);
            cur.deleteCharAt(cur.length() - 1); // backtrack
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res, new StringBuilder(), 0, 0, n);
        return res;
    }

}