// Last updated: 6/10/2026, 7:10:04 PM
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto get = [&](int x) -> int {
            int cnt = 0;
            string num = to_string(x);
            for (int i=1 ; i+1 < num.size() ; i++) {
                if (num[i-1] < num[i] && num[i] > num[i+1]) cnt++;
                if (num[i-1] > num[i] && num[i] < num[i+1]) cnt++;
            }
            return cnt;
        };
        int ans = 0;
        for (int i = num1 ; i<=num2 ; i++) ans += get(i);
        return ans;
    }
};