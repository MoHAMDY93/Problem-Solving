// Last updated: 6/10/2026, 7:26:11 PM
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;
        // handle sign
        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        // use long long to prevent overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // integer part
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;

        res += ".";
        unordered_map<long long, int> pos;
        string frac;

        while (rem != 0) {
            if (pos.count(rem)) {
                // repeating part found
                frac.insert(pos[rem], "(");
                frac.push_back(')');
                res += frac;
                return res;
            }
            pos[rem] = frac.size();
            rem *= 10;
            frac.push_back('0' + (rem / d));
            rem %= d;
        }

        res += frac;
        return res;
    }
};