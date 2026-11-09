class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > out;

        set<int> free;

        for (int i = 0; i < k; i++)
            free.insert(i);

        vector<int> cnt(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers that have finished their tasks
            while (!out.empty() && out.top().first <= arrival[i]) {
                free.insert(out.top().second);
                out.pop();
            }

            // Drop the request if all servers are busy
            if (free.empty())
                continue;

            // Find the next available server in circular order
            auto it = free.lower_bound(i % k);

            if (it == free.end())
                it = free.begin();

            int idx = *it;
            free.erase(it);

            // Assign the request
            cnt[idx]++;

            out.push({
                (long long)arrival[i] + load[i],
                idx
            });
        }

        // Find the maximum number of handled requests
        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx)
                ans.push_back(i);
        }

        return ans;
    }
};