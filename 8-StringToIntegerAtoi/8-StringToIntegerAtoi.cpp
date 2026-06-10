// Last updated: 6/10/2026, 7:28:18 PM
class Solution {
public:
    int myAtoi(string s) {
        string num;
        int sign = 1;
        int i = 0;
        while (s[i] == ' ') i++;
        if (s[i] != '+' && s[i] != '-' && (s[i] > '9' || s[i] < '0')) return 0;
        if (s[i] == '-') sign = 0 , i++;
        else if (s[i] == '+') i++;
        while (s[i] >= '0' && s[i] <= '9') num.push_back(s[i++]);
        string MAX = to_string(INT_MAX) , MIN = to_string(INT_MAX - 1);
        i = 0;
        while (num[i] == '0') i++;
        num = num.substr(i);
        cout << sign << ' ' << MAX << ' ' << MIN << ' ' << num << "\n";
        if (sign && num.size() > MAX.size()) return INT_MAX;
        else if (!sign && num.size() > MIN.size()) return INT_MIN;
        
        long long n = 0;
        for (char c : num) {
            n = n * 10LL + (c - '0');
        }
        cout << n << "\n";
        if (!sign) n *= -1LL;
        if (n > INT_MAX) n = INT_MAX;
        if (n < INT_MIN) n = INT_MIN;
        return n;
    }
};