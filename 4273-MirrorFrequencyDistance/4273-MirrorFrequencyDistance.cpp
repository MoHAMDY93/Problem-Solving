// Last updated: 6/10/2026, 7:08:06 PM
class Solution {
public:
    int mirrorFrequency(string s) {
        map<char , int> mp;
        for (auto c : s) {
            mp[c]++;
            // if ('a' <= c && c <= 'z') {
            //     mp['z' - (c - 'a')]++;
            // } else {
            //     mp['9' - (c - '0')]++;
            // }
        }
        int ans = 0;
        set<char> st;
        for (auto c : s) {
            if (!st.count(c)) {            
                if ('a' <= c && c <= 'z') {
                    char mirr = 'z' - (c - 'a');
                    cout << mirr << '\n';
                    ans += abs(mp[c] - (mp.count(mirr) ? mp[mirr] : 0));
                    st.insert(mirr);
                } else {
                    char mirr = '9' - (c - '0');
                    ans += abs(mp[c] - (mp.count(mirr) ? mp[mirr] : 0));
                    st.insert(mirr);
                }
                st.insert(c);
            }
        }
        return ans;
    }
};