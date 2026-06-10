// Last updated: 6/10/2026, 7:20:42 PM
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        sort(a.begin() , a.end());
        int diff = a[1] - a[0];
        for(int i=1 ; i<a.size() ; i++) if(a[i] - a[i-1] != diff) return false;
        return true;
    }
};