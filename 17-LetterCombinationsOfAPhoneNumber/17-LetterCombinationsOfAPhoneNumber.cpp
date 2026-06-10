// Last updated: 6/10/2026, 7:28:06 PM
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};        
        vector<string> ans;
        string a[] = {"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        function<void(int, string)> backtrack = [&](int i, string curr) {
            if(i == digits.size()) {
                ans.push_back(curr);
                return;
            }
            int idx = digits[i] - '0' - 2;
            for(char c : a[idx]) {
                backtrack(i + 1, curr + c);
            }
        };
        backtrack(0, "");
        return ans;
    }

};