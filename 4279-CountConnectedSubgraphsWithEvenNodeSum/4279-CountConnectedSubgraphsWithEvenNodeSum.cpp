// Last updated: 6/10/2026, 7:08:05 PM
class Solution {
public:
    bool isComp(int mask , vector<vector<int>>& g , int n) {
        int start = -1;
        for (int b=0 ; b<n ; b++) {
            if ((mask >> b) & 1) {start = b; break;}
        }
        if (start == -1) return false;
        int nm = (1 << start);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (((nm >> v) & 1) || !((mask >> v) & 1)) continue;
                nm |= (1 << v);
                q.push(v);
            }
        }
        return mask == nm;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        // complete search
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        for (int i=0 ; i < (1 << n) ; i++) {
            int sum = 0;
            vector<int> comp;
            for (int b = 0 ; b<n ; b++) {
                if ((i >> b) & 1) comp.push_back(b) , sum += nums[b]; 
            }
            if (sum & 1) continue;
            if (isComp(i , g , n)) cnt++;
        }
        return cnt;
    }
};