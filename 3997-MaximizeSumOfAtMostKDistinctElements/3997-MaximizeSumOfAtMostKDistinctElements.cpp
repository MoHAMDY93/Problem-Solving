// Last updated: 6/10/2026, 7:10:36 PM
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& a, int k) {
        sort(a.begin(),a.end(),greater<int>());
        a.erase(unique(a.begin(),a.end()),a.end());   // distinct
        if(a.size()>k) a.resize(k);                  // BUG: if a.size()<k do NOTHING extra
        return a;                                    // missing smaller uniques
    }
};