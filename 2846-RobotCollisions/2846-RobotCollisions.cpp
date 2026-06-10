// Last updated: 6/10/2026, 7:15:27 PM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end()); // sort by position

        stack<int> st; // stores indices in robots[] of 'R' robots

        for (int i = 0; i < n; i++) {
            auto& [pos, h, d, idx] = robots[i];

            if (d == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && h > 0) {
                    int j = st.top();
                    auto& [rpos, rh, rd, ridx] = robots[j];

                    if (rh < h) {
                        // right robot dies, left robot loses 1 health and continues
                        st.pop();
                        h--;
                        rh = 0;
                    } 
                    else if (rh == h) {
                        // both die
                        st.pop();
                        rh = 0;
                        h = 0;
                        break;
                    } 
                    else {
                        // left robot dies, right robot loses 1 health
                        rh--;
                        h = 0;
                        break;
                    }
                }
            }
        }

        vector<pair<int,int>> ans; // (original index, final health)
        for (auto& [pos, h, d, idx] : robots) {
            if (h > 0) ans.push_back({idx, h});
        }

        sort(ans.begin(), ans.end()); // restore original order

        vector<int> res;
        for (auto& [idx, h] : ans) res.push_back(h);

        return res;
    }
};