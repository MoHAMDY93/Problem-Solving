// Last updated: 7/6/2026, 3:15:45 AM
// قوي ؟
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin() , intervals.end() , [&](const auto& a , const auto& b) {
5            if (a[0] != b[0]) return a[0] < b[0];
6            return a[1] > b[1];
7        });
8        int prev = 0 , cnt = 0 , n = intervals.size();
9        for (int i=1 ; i<n ; i++) {
10            if (intervals[i][1] <= intervals[prev][1]) cnt++;
11            else prev = i;
12        }
13        return n - cnt;
14    }
15};