// Last updated: 6/10/2026, 7:12:25 PM
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int , set<int>> mp;
        int n = nums.size();
        for (int i=0 ; i<n ; i++) mp[nums[i]].insert(i);
        for (auto q : queries) {
            auto& st = mp[nums[q]];
            if (st.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int mn = INT_MAX;
            auto r = st.upper_bound(q);
            auto l = st.lower_bound(q);
            if (r != st.end()) 
                mn = min(mn , *r - q);
            else 
                mn = min(mn , n - q + *st.begin());
            
            if (l != st.begin()) 
                mn = min(mn , q - *prev(l));
            else
                mn = min(mn , n + q - *st.rbegin());
            
            ans.push_back(mn);
        }
        return ans;
    }
};