// Last updated: 6/10/2026, 7:07:56 PM
class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        vector<int> freq1(26 , 0) , freq2(26 , 0) , freq3(10 , 0) , freq4(4 , 0);
        for (auto c : password) {
            if ('a' <= c && c <= 'z') freq1[c - 'a']++;
            if ('A' <= c && c <= 'Z') freq2[c - 'A']++;
            if ('0' <= c && c <= '9') freq3[c - '0']++;
            if (c == '!') freq4[0]++;
            if (c == '@') freq4[1]++;
            // if (c == '!') freq4[2]++;
            if (c == '#') freq4[2]++;
            if (c == '$') freq4[3]++;
        }
        for (int i : freq1) ans += (i > 0);
        for (int i : freq2) ans += 2 * (i > 0);
        for (int i : freq3) ans += 3 * (i > 0);
        for (int i : freq4) ans += 5 * (i > 0);
        return ans;    
    }
};