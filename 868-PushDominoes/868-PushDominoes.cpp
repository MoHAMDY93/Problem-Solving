// Last updated: 6/10/2026, 7:23:22 PM
class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> forces(n, 0);
        int force = 0;
        // Left → Right pass for 'R' forces
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')      force = n;
            else if (s[i] == 'L') force = 0;
            else                  force = max(force-1, 0);
            forces[i] += force;
        }
        // Right → Left pass for 'L' forces
        force = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == 'L')      force = n;
            else if (s[i] == 'R') force = 0;
            else                  force = max(force-1, 0);
            forces[i] -= force;
        }
        // Build result
        string ans(n, '.');
        for (int i = 0; i < n; i++) {
            if (forces[i] > 0)      ans[i] = 'R';
            else if (forces[i] < 0) ans[i] = 'L';
            // else remains '.'
        }
        return ans;
    }
};