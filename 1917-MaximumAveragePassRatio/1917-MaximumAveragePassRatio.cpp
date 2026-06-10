// Last updated: 6/10/2026, 7:19:26 PM
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double sum = 0.0;
        priority_queue<pair<double , pair<int , int>>> pq;
        for(auto v : classes) {
            double curr = 1.0 * v[0] / v[1]; 
            double increase = 1.0 * (v[0] + 1) / (v[1] + 1);
            // cout << increase - curr << "\n";
            pq.push({increase - curr , {v[0] , v[1]}});
            sum += curr;
        }
        while(extraStudents--) {
            auto [nxt , p] = pq.top(); pq.pop();
            // cout << nxt << "\n";
            double curr = (1.0 * p.first / p.second) + nxt;
            sum += nxt;
            double increase = 1.0 * (p.first + 2) / (p.second + 2);
            pq.push({increase - curr , {p.first+1 , p.second+1}});
        }
        cout << sum << "\n";
        return sum / (1.0 * classes.size());
    }
};