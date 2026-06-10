// Last updated: 6/10/2026, 7:18:24 PM
class Robot {
public:
    vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    int curr_dir = 0;
    pair<int , int> curr_pos = {0 , 0};
    int w , h;
    vector<string> v = {"East" , "North" , "West" , "South"};
    Robot(int width, int height) {
        w = width , h = height;
    }
    
    void step(int num) {
        num %= 2 * (w + h) - 4;
         if (num == 0) {
            if (curr_pos == make_pair(0, 0)) {
                curr_dir = 3;
            }
            return;
        }
        while (num) {
            int nx = curr_pos.first + dirs[curr_dir].first , ny = curr_pos.second + dirs[curr_dir].second;
            if (0 > nx || nx >= w || 0 > ny || ny >= h) {
                curr_dir = (curr_dir + 1) % 4;
                continue;
            }
            curr_pos = {nx , ny};
            num--;
        }
    }
    
    vector<int> getPos() {
        return {curr_pos.first , curr_pos.second};
    }
    
    string getDir() {
        return v[curr_dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */