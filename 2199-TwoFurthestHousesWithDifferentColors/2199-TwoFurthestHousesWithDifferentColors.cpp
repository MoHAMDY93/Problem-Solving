// Last updated: 6/10/2026, 7:18:16 PM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            if (colors[i] ^ colors[n-1]) {
                ans = max(ans , n-1 - i);
                break;
            }
        }
        for (int i=n-1 ; i>=0 ; i--) {
            if (colors[i] ^ colors[0]) {
                ans = max(ans , i);
                break;
            }
        }
        return ans ? ans : -1;
    }
};