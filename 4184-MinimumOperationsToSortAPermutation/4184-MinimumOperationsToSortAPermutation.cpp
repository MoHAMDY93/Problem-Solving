// Last updated: 6/10/2026, 7:08:27 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx;
        for (int i=0 ; i<n ; i++) {
            if (nums[i] == 0) idx = i;
        }
        bool asc = true , desc = true;
        for (int i=0 ; i<n ; i++) {
            if (nums[(idx + i) % n] != i) { asc = false; break; }
        }
        for (int i=0 ; i<n ; i++) {
            if (nums[(idx - i + n) % n] != i) { desc = false; break; }
        }
        if (!asc && !desc) return -1;
        queue<pair<pair<int , bool> , int>> q;
        vector<vector<bool>> vis(n , vector<bool>(2 , false));
        if (asc)  q.push({{idx , false} , 0}) , vis[idx][0] = true;
        if (desc) q.push({{idx , true} , 0}) , vis[idx][1] = true;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();

            int idx = curr.first.first , dist = curr.second;
            bool rev = curr.first.second;

            if (idx == 0 && !rev) return dist;
            int nidx_rev = n - 1 - idx;
            bool nrev = rev ^ 1;
            if (!vis[nidx_rev][nrev]) {
                vis[nidx_rev][nrev] = 1;
                q.push({{nidx_rev,nrev} , dist+1});
            }
            int nidx_rot = (idx - 1 + n) % n;
            if (!vis[nidx_rot][rev]) {
                vis[nidx_rot][rev] = 1;
                q.push({{nidx_rot , rev} , dist + 1});
            }
        }
        return -1;
    }
};