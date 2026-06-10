// Last updated: 6/10/2026, 7:21:11 PM
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq;
        long long sum = 0;
        for (auto i : target) pq.push(i) , sum += i;
        while (sum != n) {
            int curr = pq.top(); pq.pop();
            sum -= curr;
            if (sum == 1) return true;
            if (sum == 0 || curr <= sum) return false;
            int mod = curr % sum;
            if (mod == 0) return false;
            pq.push(mod);
            sum += mod;
        }
        return true;
    }
};