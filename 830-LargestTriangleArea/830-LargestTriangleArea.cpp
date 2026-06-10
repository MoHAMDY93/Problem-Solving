// Last updated: 6/10/2026, 7:23:26 PM
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& a) {
        int n = a.size();
        double ans = 0;
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                for(int k = j+1 ; k<n ; k++) {
                    // Area=0.5​⋅∣x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​)∣
                    double area = 0.5 * abs(a[i][0] * (a[j][1] - a[k][1]) + a[j][0] * (a[k][1] - a[i][1])
                                            + a[k][0] * (a[i][1] - a[j][1]));
                    ans = max(ans , area);
                }
            }
        }
        return ans;
    }
};