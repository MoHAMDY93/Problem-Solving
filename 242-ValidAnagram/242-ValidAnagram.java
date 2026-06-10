// Last updated: 6/10/2026, 7:25:30 PM
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] freq = new int[26];
        Arrays.fill(freq , 0);
        for (char c : s.toCharArray()) freq[c - 'a']++;
        for (char c : t.toCharArray()) {
            if (freq[c - 'a'] == 0) return false;
            freq[c - 'a']--;
        }
        for (int i=0 ; i<26 ; i++) {
            if (freq[i] > 0) return false;
        }
        return true;
    }
}