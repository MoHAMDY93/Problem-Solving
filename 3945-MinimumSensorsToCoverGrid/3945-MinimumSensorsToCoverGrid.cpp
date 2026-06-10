// Last updated: 6/10/2026, 7:11:11 PM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        return ceil(1.0 * n / (2*k + 1)) * ceil(1.0 * m / (2*k+1));
    }
};