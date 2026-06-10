// Last updated: 6/10/2026, 7:27:23 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        intervals.push_back({INT_MAX , INT_MAX});
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i=1 ; i<=n ; i++) {
            if (end >= intervals[i][0]) end = max(end , intervals[i][1]);
            else {
                ans.push_back({start , end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }   
        return ans;
    }
};