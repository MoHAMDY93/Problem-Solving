// Last updated: 6/10/2026, 7:11:59 PM
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> a(n , INT_MAX);
        a[0] = 0;
        for(auto r : restrictions) {
            a[r[0]] = r[1];
        }
        for(int i=1 ; i<n ; i++) {
            a[i] = min(a[i] , a[i-1] + diff[i-1]);
        }
        for(int i=n-2 ; i>=0 ; i--) {
            a[i] = min(a[i] , a[i+1] + diff[i]);
        }  

        return *max_element(a.begin() , a.end());
    }
};