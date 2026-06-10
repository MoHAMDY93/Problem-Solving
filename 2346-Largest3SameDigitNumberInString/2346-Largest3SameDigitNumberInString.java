// Last updated: 6/10/2026, 7:17:19 PM
class Solution {
    public String largestGoodInteger(String num) {
        int res = -1;
        char prev = num.charAt(0);
        int cnt = 0;
        for (char c : num.toCharArray()) {
            if (c == prev) cnt++;
            else {
                if (cnt >= 3 && (prev - '0') > res) res = (prev - '0');
                prev = c;
                cnt = 1;
            }
        }
        if (cnt >= 3 && (prev - '0') > res) res = (prev - '0');
        if(res == -1) return "";
        String result = String.valueOf((char)('0' + res)).repeat(3);
        return result;
    }
}