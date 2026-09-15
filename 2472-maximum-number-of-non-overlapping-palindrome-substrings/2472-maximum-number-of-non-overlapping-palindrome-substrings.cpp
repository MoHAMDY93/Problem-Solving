class Solution {
private:
// Transform string: "abba" -> "^#a#b#b#a#$"
string preprocess(const string &s) {
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    return t;
}

// Manacher's Algorithm to compute palindrome radii
vector<int> manacher(const string &t) {
    string s = preprocess(t);
    int n = s.size();
    vector<int> p(n, 0);
    int c = 0, r = 0; // center and right boundary

    for (int i = 0; i < n; i++) {
        int mirror = 2 * c - i;
        if (i < r)
            p[i] = min(r - i, p[mirror]);

        // Expand around center i
        int a = i + (1 + p[i]);
        int b = i - (1 + p[i]);
        while (a < n && b >= 0 && s[a] == s[b]) {
            p[i]++;
            a++;
            b--;
        }

        // Update center and right boundary
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

// Check if s[l..r] is palindrome using Manacher's result
bool isPalindrome(int l, int r, const vector<int> &p) {
    // Map original indices to transformed string indices
    int center = l + r + 2; // +2 because of '^#' at start
    int length = r - l + 1;
    return p[center] >= length;
}

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        auto p = manacher(s);
        /*
            dp[idx][start] -> size = idx - start + 1 , boolean palindrome = isPalindrome(start , idx)
        */
        vector<vector<int>> memo(n , vector<int> (n , -1));
        auto dp = [&](this auto&& dp , int idx , int start) -> int {
            // reached the end
            if (idx == n) return 0;
            auto &ret = memo[idx][start];
            if (~ret) return ret;

            // add the current character to the curr string
            ret = dp(idx+1 , start);
            // skip and start a new string
            ret = max(ret , dp(idx+1 , idx+1));
            // if the curr string is valid -> [sz >= k && isPlaindrome(curr) = true], then maximize between those two paths
            int sz = idx - start + 1;
            if (sz >= k && isPalindrome(start , idx , p)) ret = max(ret , 1 + dp(idx+1 , idx+1));

            return ret; 
        };

        return dp(0 , 0);
    }
};