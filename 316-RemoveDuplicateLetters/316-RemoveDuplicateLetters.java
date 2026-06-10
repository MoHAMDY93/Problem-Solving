// Last updated: 6/10/2026, 7:25:16 PM
class Solution {
    public String removeDuplicateLetters(String s) {
        char[] ch = s.toCharArray();
        int[] freq = new int[26];
        boolean[] vis = new boolean[26];
        for (char c : ch) freq[c - 'a']++;
        Stack<Character> st = new Stack<>();
        for (char c : ch) {
            freq[c - 'a']--;
            if(vis[c - 'a']) continue;
            while(!st.empty() && c < st.peek() && freq[st.peek() - 'a'] != 0)
                vis[st.pop() - 'a'] = false;
            st.push(c);
            vis[c - 'a'] = true;
        }  
        StringBuilder sb = new StringBuilder();
        while(!st.empty()) {
            sb.insert(0, st.pop());
        }
        return sb.toString();
    }
}