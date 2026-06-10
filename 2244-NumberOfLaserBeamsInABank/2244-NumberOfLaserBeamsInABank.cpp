// Last updated: 6/10/2026, 7:18:01 PM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int n = bank.size();
        int prev = -1;
        for(int i=0 ; i<n ; i++) {
            int cnt = 0;
            for(auto c : bank[i]) cnt += (c == '1');
            if(cnt == 0) continue;
            if(~prev) res += cnt * prev;
            prev = cnt;
        }
        return res;
    }
};