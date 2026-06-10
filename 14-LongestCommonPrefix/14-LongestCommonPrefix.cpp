// Last updated: 6/10/2026, 7:28:09 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans;
        for (int i = 0; i < strs[0].length(); i++) {
            bool flag = true;
            char temp = strs[0][i];
    //        cout<<temp<<endl;
            for (string d: strs) {
                if (d[i] != temp) {
    //                cout<<d[i]<<' ';
                    flag = false;
                    break;
                }
            }
            if (flag)ans += temp;
            else break;
        }
        return ans;
    }
};