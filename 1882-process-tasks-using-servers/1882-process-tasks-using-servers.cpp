class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long , int>, vector<pair<long long, int>>, greater<pair<long long , int>>> out;
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int , int>>> free;
        for (int i=0 ; i<servers.size() ; i++) {
            free.push({servers[i], i});
        }
        vector<int> ans;
        long long curr_time = 0;
        for (int i=0 ; i<tasks.size(); i++) {
            curr_time = max(curr_time, (long long)i);
            while (!out.empty() && out.top().first <= curr_time) {
                int idx = out.top().second;
                free.push({servers[idx], idx});
                out.pop();
            }
            if (free.empty()) {
                curr_time = out.top().first;
                while (!out.empty() && out.top().first == curr_time) {
                    int idx = out.top().second;
                    free.push({servers[idx], idx});
                    out.pop();
                }
            }
            ans.push_back(free.top().second);
            out.push({curr_time + tasks[i], free.top().second});
            free.pop();
        }
        return ans;
    }
};