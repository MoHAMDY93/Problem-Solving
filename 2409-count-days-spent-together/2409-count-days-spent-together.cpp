class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto get_day = [&](string date) -> int {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            vector<int> monthDays = {
                31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31
            };

            int prev_days = 0;

            for (int i = 0; i < month - 1; i++) {
                prev_days += monthDays[i];
            }

            return prev_days + day;
        };
        int start = max(get_day(arriveAlice), get_day(arriveBob));
        int end = min(get_day(leaveAlice), get_day(leaveBob));
        // cout << get_day(arriveAlice) << '\n' << get_day(arriveBob) << '\n';
        // cout << get_day(leaveAlice) << '\n' << get_day(leaveBob) << '\n';
        // cout << start << ' ' << end << '\n';
        return (end >= start ? end - start + 1 : 0);
    }
};