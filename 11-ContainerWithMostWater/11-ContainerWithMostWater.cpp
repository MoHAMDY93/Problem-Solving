// Last updated: 6/10/2026, 7:28:15 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0 , l = 0 , r = n-1;
        while(l < r) {
            ans = max(ans , min(height[l] , height[r]) * (r - l));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};