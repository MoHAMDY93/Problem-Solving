class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asts) {
        long long curr = mass;
        sort(asts.begin() , asts.end());
        for (auto i : asts) {
            if (curr < i) return false;
            curr += i;
        }
        return true;
    }
};