// Last updated: 6/10/2026, 7:18:03 PM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int cnt = 0;
        bool hasCentral = false;

        for (const string& word : words) {
            freq[word]++;
        }

        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            
            if (word == rev) {
                // Palindromic word (like "aa")
                cnt += (count / 2) * 4;
                if (count % 2 == 1) hasCentral = true; // One leftover can go in the middle
            } else if (freq.count(rev)) {
                int pairs = min(count, freq[rev]);
                cnt += pairs * 4;
                freq[rev] = 0;  // Avoid double counting
                freq[word] = 0;
            }
        }

        if (hasCentral) cnt += 2; // One palindromic word can go in the center

        return cnt;
    }

};