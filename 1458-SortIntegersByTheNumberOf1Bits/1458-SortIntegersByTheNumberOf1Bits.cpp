// Last updated: 6/10/2026, 7:21:21 PM
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int , int>> a;
        for (auto i : arr) {
            a.push_back({__builtin_popcount(i) , i});
        } 
        
        sort(a.begin() , a.end());
        
        vector<int> ans;
        for (auto [f , s] : a) 
            ans.push_back(s);

        return ans;
    }
};