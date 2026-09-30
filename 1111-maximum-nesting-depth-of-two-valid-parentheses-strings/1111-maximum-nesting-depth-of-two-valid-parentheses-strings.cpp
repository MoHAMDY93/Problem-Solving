class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        /*
            i just noticed that the solution for this problem is just a straightforward usin stack
            initially we have an empty stack:
            and for the first open par we will assign one to, and now we have two diffrent coming ways:
            1) meet an extra open one:
                then we have to flip the result from 1 to 0 -> this is an optimal way to make the resulting depth minimized
            2) meet a closing one:
                just assign it the value of its pair and go away
        */
        stack<int> st;
        vector<int> ans;
        for (auto c : seq) {
            if (c == '(') {
                if (st.empty()) st.push(1) , ans.push_back(1);
                else {
                    int nxt = st.top() ^ 1;
                    st.push(nxt) , ans.push_back(nxt);
                }
            } else {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};