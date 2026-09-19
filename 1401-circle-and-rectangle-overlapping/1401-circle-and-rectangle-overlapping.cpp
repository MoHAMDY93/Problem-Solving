class Solution {
public:
    // Function to get line coefficients from two points
    tuple<int,int,int> line(int x1, int y1, int x2, int y2) {
        int a = y2 - y1;
        int b = x1 - x2;
        int c = x2*y1 - y2*x1;
        return {a, b, c};
    }
    double sd(int a, int b, int c, int x0, int y0) {
        return fabs(a*x0 + b*y0 + c) / sqrt(a*a + b*b);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // vector<pair<int , int>> rect = {
        //     {x1 , y1},
        //     {x2 , y1},
        //     {x2 , y2},
        //     {x1 , y2}
        // };
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        // for (int i=0 ; i<4 ; i++) {
        //     auto [xf , yf] = rect[i];
        //     auto [xs , ys] = rect[(i + 1) % 4];
        //     auto [a , b , c] = line(xf , yf , xs , ys);
        //     double dist = sd(a , b , c , xCenter , yCenter);
        //     cout << dist << '\n';
        //     if (dist <= radius) return true;
        // }
        int dx = closestX - xCenter , dy = closestY - yCenter;
        int dist = dx * dx + dy * dy;
        return dist <= radius * radius;
        // return false;
    }
};