// Last updated: 6/10/2026, 7:24:19 PM
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<int> st;
        int prev_time = 0;
        
        for (auto& log : logs) {
            int id, time;
            string type;
            parseLog(log, id, type, time);
            
            if (type == "start") {
                if (!st.empty())
                    times[st.top()] += time - prev_time;  // running function till now
                st.push(id);
                prev_time = time;
            } else {
                times[st.top()] += time - prev_time + 1;  // inclusive end
                st.pop();
                prev_time = time + 1; // next function resumes after current ends
            }
        }
        return times;
    }
    
private:
    void parseLog(const string& log, int& id, string& type, int& time) {
        int pos1 = log.find(':'), pos2 = log.find(':', pos1 + 1);
        id = stoi(log.substr(0, pos1));
        type = log.substr(pos1 + 1, pos2 - pos1 - 1);
        time = stoi(log.substr(pos2 + 1));
    }
};