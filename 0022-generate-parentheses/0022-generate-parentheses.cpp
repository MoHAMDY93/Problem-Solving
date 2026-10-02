class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        auto get = [&](this auto&& get , int rem , int open) {
            if (rem == 0) {
                if (open == 0) ans.push_back(s);
                return;
            }
            {
                s.push_back('(');
                get(rem - 1 , open + 1);
                s.pop_back();
            }
            if (open > 0) {
                s.push_back(')');
                get(rem - 1 , open - 1);
                s.pop_back();
            }
        };
        get(2 * n , 0);
        return ans;
    }
};