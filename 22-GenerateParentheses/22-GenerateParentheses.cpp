// Last updated: 6/10/2026, 7:27:59 PM
class Solution {
public:
    int total;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        total = n;
        string curr = "";
        gen(0 , 0 , curr);
        return ans;
    }
private:
    void gen(int open , int cnt , string curr) {
        if (curr.size() == 2 * total) {
            ans.push_back(curr);
            return;
        }
        if (open) {
            curr.push_back(')');
            gen(open-1 , cnt , curr);
            curr.pop_back();
        }
        if (cnt < total) {
            curr.push_back('(');
            gen(open+1 , cnt+1 , curr);
            curr.pop_back();
        }
    }
};