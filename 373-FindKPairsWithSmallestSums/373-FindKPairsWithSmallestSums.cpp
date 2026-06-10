// Last updated: 6/10/2026, 7:25:07 PM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() , m = nums2.size();
        priority_queue<
            tuple<int , int , int> ,
            vector<tuple<int , int , int>> ,
            greater<tuple<int , int , int>>> pq;
        vector<vector<int>> ans;
        for (int i=0 ; i<n ; i++) pq.push({nums1[i] + nums2[0] , i , 0});
        while (k--) {
            auto [_ , i , j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i] , nums2[j]});
            if (j + 1 < m)
                pq.push({nums1[i] + nums2[j+1] , i , j+1});
        }
        return ans;
    }
};