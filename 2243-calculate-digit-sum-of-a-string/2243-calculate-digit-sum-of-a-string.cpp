class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;
        while (ans.size() > k) {
            string t;
            int sum = 0;
            for (int i=0 ; i<ans.size() ; i++) {
                if (i > 0 && i % k == 0) t.append(to_string(sum)), sum = 0;
                sum += ans[i] - '0';
            }
            t.append(to_string(sum));
            ans = t;
            // cout << ans << endl;
        }
        return ans;
    }
};