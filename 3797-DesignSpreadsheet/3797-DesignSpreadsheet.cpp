// Last updated: 6/10/2026, 7:12:02 PM
class Spreadsheet {
public:
    map<string , int> mp;
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        // grid = vector<vector<int>>(rows+1 , vector<int> (26 , 0));
    }
    
    void setCell(string cell, int value) {
        // int col = cell[0] - 'A';
        // string str = cell.substr(1);
        // int row = stoi(str);
        mp[cell] = value;  
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        string str = cell.substr(1);
        int row = stoi(str);
        mp.erase(cell);
    }
    
    int getValue(string formula) {
        // checks for cell or number
        string val1 , val2;
        int idx = 1;
        while(formula[idx] != '+') val1.push_back(formula[idx++]);
        while(++idx < formula.size()) val2.push_back(formula[idx]);
        // int ans = 0;
        // if('A' <= val1[0] && val1[0] <= 'Z') {
        //     int col = val1[0] - 'A';
        //     string str = val1.substr(1);
        //     int row = stoi(str);
        //     ans += grid[row][col];
        // } else {
        //     ans += stoi(val1);
        // }
        // if('A' <= val2[0] && val2[0] <= 'Z') {
        //     int col = val2[0] - 'A';
        //     string str = val2.substr(1);
        //     int row = stoi(str);
        //     ans += grid[row][col];
        // } else {
        //     ans += stoi(val2);
        // }
        int ans = 0;
        if('A' <= val1[0] && val1[0] <= 'Z')
            ans += (mp.count(val1) ? mp[val1] : 0);
        else 
            ans += stoi(val1);
        if('A' <= val2[0] && val2[0] <= 'Z') 
            ans += (mp.count(val2) ? mp[val2] : 0);
        else 
            ans += stoi(val2);
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */