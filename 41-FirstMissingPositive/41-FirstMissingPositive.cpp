// Last updated: 6/10/2026, 7:27:33 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int &x : a)
            if(x <= 0 || x > n)
                x = n + 1;

        for(int i = 0; i < n; i++) {
            int val = abs(a[i]);
            if(val >= 1 && val <= n) {
                if(a[val - 1] > 0)
                    a[val - 1] = -a[val - 1];
            }
        }
        for(int i = 0; i < n; i++)
            if(a[i] > 0)
                return i + 1;

        return n + 1;
    }
};