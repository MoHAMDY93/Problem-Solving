// Last updated: 7/29/2026, 2:18:36 AM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int freq[26] = {0};
5        for (auto& c : s) freq[c - 'a']++;
6        string left , right , mid;
7        for (int c = 0 ; c < 26 ; c++) {
8            if (freq[c] == 0) continue;
9            if (freq[c] & 1) mid.push_back(c + 'a');
10            int len = freq[c] / 2;
11            left.append(string(len , c + 'a'));
12            right.append(string(len , c + 'a'));
13        }
14        reverse(begin(right) , end(right));
15        return left + mid + right;
16    }
17};