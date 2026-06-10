// Last updated: 6/10/2026, 7:22:16 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& doms) {
        int n = doms.size() , cnt = 0;
        map<pair<int,int> , int>mp;
        for(auto i : doms) {
            int a = i[0], b = i[1];
            pair<int,int> key = a < b ? make_pair(a, b) : make_pair(b, a);
            cnt += mp[key];
            mp[key]++;
        }
        return cnt;
    }
};