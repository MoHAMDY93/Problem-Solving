// Last updated: 6/13/2026, 3:56:33 PM
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        auto convert = [&](const string& s) -> char {
5            int sum = 0;
6            for (char c : s) sum += weights[c - 'a'];
7            sum %= 26;
8            return (char)('a' + (25 - sum));
9        };
10        string ans;
11        for (auto& word : words) {
12            ans += convert(word);
13        }
14        return ans;
15    }
16};