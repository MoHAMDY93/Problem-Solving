class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int , int>> qr_idx;
        for (int i=0 ; i<queries.size() ; i++) {
            qr_idx.emplace_back(queries[i], i);
        }
        unordered_map<int , int> cnt;
        sort(begin(logs) , end(logs) , [](auto& A, auto& B) {
            return A[1] < B[1];
        });
        sort(qr_idx.begin() , qr_idx.end());
        vector<int> ans(queries.size());
        int l = 0, r=0, curr_cnt = 0;
        for (int i=0 ; i<queries.size() ; i++) {
            auto [val, idx] = qr_idx[i];
            while (l < logs.size() && logs[l][1] < val - x) {
                if (cnt.count(logs[l][0])) cnt[logs[l][0]]--;
                if (!cnt[logs[l][0]]) cnt.erase(logs[l][0]);
                l++;        
            }
            if (l > r) r = l;
            while (r < logs.size() && logs[r][1] <= val) {
                cnt[logs[r][0]]++;
                r++;
            }
            ans[idx] = (n - cnt.size());
        }
        return ans;
    }
};