class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] ||   
            rec2[2] <= rec1[0] ||   // rec2 is completely left of rec1
            rec1[3] <= rec2[1] ||   // rec1 is completely below rec2
            rec2[3] <= rec1[1]) {   // rec2 is completely below rec1
            return false;
        }

        return true;
    }
};