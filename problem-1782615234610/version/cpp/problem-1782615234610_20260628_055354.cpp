// Last updated: 6/28/2026, 5:53:54 AM
1class Solution {
2public:
3    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intervals, int freeStart, int freeEnd) {
4        sort(intervals.begin() , intervals.end());
5        intervals.push_back({INT_MAX , INT_MAX});
6        vector<vector<int>> ans;
7        int start = intervals[0][0] , end = intervals[0][1];
8        for (auto& v : intervals) {
9            int curr_s = v[0] , curr_e = v[1];
10            if (curr_s <= end+1) end = max(curr_e , end);
11            else {
12                ans.push_back({start , end});
13                start = curr_s , end = curr_e;
14            }
15        }
16        // ans.push_back()
17        for (auto& v : ans) {
18            cout << v[0] << ' ' << v[1] << '\n';
19        }
20        vector<vector<int>> res;
21        for (auto& v : ans) {
22            int curr_s = v[0] , curr_e = v[1];
23            // full intersection
24            if (freeStart >= curr_s && freeEnd <= curr_e) {
25                // cout << "OK\n";
26                if (curr_s <= freeStart-1)
27                    res.push_back({curr_s , freeStart-1});
28                if (freeEnd+1 <= curr_e)
29                    res.push_back({freeEnd+1 , curr_e});
30            } else if (freeStart <= curr_s && curr_s <= freeEnd) {
31                if (freeEnd+1 <= curr_e)
32                    res.push_back({freeEnd+1 , curr_e});
33            } else if (freeStart <= curr_e && curr_e <= freeEnd) {
34                if (curr_s <= freeStart-1)
35                    res.push_back({curr_s , freeStart-1});
36            } else {
37                res.push_back({curr_s , curr_e});
38            }
39        }
40        return res;
41    }
42};