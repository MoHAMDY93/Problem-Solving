// Last updated: 7/19/2026, 3:28:40 AM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        int freq[26] = {0};
5        bitset<26> seen;
6        string stack;
7        for (auto c : s) freq[c - 'a']++;
8        for (auto c : s) {
9            int x = c - 'a';
10            freq[x]--;
11            if (seen.test(x)) continue;
12            while (!stack.empty() && stack.back() > c && freq[stack.back() - 'a']) {
13                seen.reset(stack.back() - 'a');
14                stack.pop_back();
15            }
16            stack.push_back(c);
17            seen.set(x);
18        }
19        return stack;
20    }
21};