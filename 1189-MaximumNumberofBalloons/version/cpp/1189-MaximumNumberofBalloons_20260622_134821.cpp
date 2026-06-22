// Last updated: 6/22/2026, 1:48:21 PM
1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        vector<int> freq(26 , 0);
5        for (auto c : text) freq[c - 'a']++;
6        return min({freq['b' - 'a'] , freq['a' - 'a'] ,freq['l' - 'a']/2 ,freq['o' - 'a']/2 ,freq['n' - 'a']});
7    }
8};