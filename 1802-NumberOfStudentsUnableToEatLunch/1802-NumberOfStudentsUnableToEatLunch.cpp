// Last updated: 6/10/2026, 7:20:02 PM
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        reverse(sandwiches.begin() , sandwiches.end());
        queue<int> q;
        int cnt = 0 , circles = 0 , squares = 0;
        for (auto i : students) {
            q.push(i);
            (i == 0 ? circles : squares)++;
        }
        while (!q.empty()) {
            if (q.front() == sandwiches.back()) {
                (q.front() == 0 ? circles : squares)--;
                q.pop();
                sandwiches.pop_back();
            } else if (sandwiches.back() == 0) {
                if (circles == 0) {
                    cnt += squares;
                    break;
                } else {
                    q.push(q.front());
                    q.pop();
                }  
            } else {
                if (squares == 0) {
                    cnt += circles;
                    break;
                } else {
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        return cnt;
    }
};