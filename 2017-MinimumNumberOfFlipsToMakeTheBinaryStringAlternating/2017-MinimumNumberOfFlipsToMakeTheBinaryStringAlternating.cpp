// Last updated: 6/10/2026, 7:19:08 PM
class Solution {
public:
    int minFlips(string s) {
        const int sLength = s.length();
        int zeroOne = 0;
        for (int index = 0; index < sLength; ++index) {
            zeroOne += s[index] == '0' + (index & 1);
        }
        int ret = min(zeroOne, sLength - zeroOne);
        if (!(sLength & 1)) {
            return ret;
        }
        for (int index = 0; index < sLength; ++index) {
            zeroOne = sLength - 1 - zeroOne + 2 * (s[index] == '0');
            ret = min({ret, zeroOne, sLength - zeroOne});
        }
        return ret;
    }
};