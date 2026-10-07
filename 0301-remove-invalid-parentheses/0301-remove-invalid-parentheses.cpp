class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<string> total;
        string curr;
        auto get = [&](this auto&& get , int i , int open) -> void {
            if (i == n) {
                if (open == 0) total.push_back(curr);
                return; 
            }
            // skip
            if (s[i] == '(' || s[i] == ')')
                get(i+1 , open);
            
            // take
            if (s[i] == '(') {
                curr.push_back(s[i]);
                get(i+1 , open+1);
                curr.pop_back();
            } else if (s[i] == ')') {
                if (!open) return;
                curr.push_back(s[i]);
                get(i+1 , open-1);
                curr.pop_back();
            } else {
                curr.push_back(s[i]);
                get(i+1 , open);
                curr.pop_back();
            }
        };
        get(0 , 0);
        // return total;
        int maxi = 0;
        for (auto ss : total) maxi = max(maxi , (int)ss.size());
        set<string> valid;
        for (auto ss : total) {
            if (ss.size() == maxi) valid.insert(ss);
        }
        return vector<string> (begin(valid) , end(valid));
    }
};