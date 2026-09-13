class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int best = 0;
        for (int dr = -(n - 1) ; dr <= (n - 1) ; dr++) {
            for (int dc = -(n-1) ; dc <= (n-1) ; dc++) {
                int overlap = 0;
                for (int i=0 ; i<n ; i++) {
                    for (int j=0 ; j<n ; j++) {
                        if (img2[i][j] == 0) continue;
                        int nx = i + dr , ny = j + dc;
                        if (0 <= nx && nx < n && 0 <= ny && ny < n && img1[nx][ny] == 1) overlap++; 
                    }
                }
                best = max(best , overlap);
            }
        }
        return best;
    }
};