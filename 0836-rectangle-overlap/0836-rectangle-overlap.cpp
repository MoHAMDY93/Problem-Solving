class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /*
            a rectangle is not overlaping with the other if:
            cond1: rec1 left edge is to the right of the rec2 right edge
                rec1.x1 >= rec2.x2
            cond2: rec1 right edge is to the left of the rec2 left edge
                rec1.x2 <= rec1.x1
            cond1: rec1 bottom edge is to the top of the rec2 top edge
                rec1.y1 >= rec2.y2
            cond1: rec1 top edge is to the bottom of the rec2 top edge
                rec1.y2 <= rec2.y1
        */
        if (rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]) return false;
        return true;
    }
};