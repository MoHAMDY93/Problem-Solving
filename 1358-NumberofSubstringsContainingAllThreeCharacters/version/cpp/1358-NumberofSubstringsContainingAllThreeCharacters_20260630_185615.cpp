// Last updated: 6/30/2026, 6:56:15 PM
1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        unordered_map<int , int> mp;
5        int n = s.size() , l = 0 , ans = 0;
6        for (int r = 0 ; r < n ; r++) {
7            if (s[r] == 'a' || s[r] == 'b' || s[r]== 'c') {
8                mp[s[r]]++;
9            }
10            while (mp.size() == 3) {
11                ans += n - r;
12                if (s[l] == 'a' || s[l] == 'b' || s[l] == 'c') {
13                    mp[s[l]]--;
14                    if (mp[s[l]] == 0) mp.erase(s[l]);
15                }
16                l++;
17            }
18        }   
19        return ans;
20    }
21};