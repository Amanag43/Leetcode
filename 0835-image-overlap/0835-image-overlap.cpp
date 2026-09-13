class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       vector<pair<int, int>> ones_img1;
        vector<pair<int, int>> ones_img2;
        int n = img1.size();
        for(int r = 0 ; r<n ; r++){
            for( int c =0; c<n; c++){
            if(img1[r][c]==1){
            ones_img1.push_back({r,c});
            }
        }
        }
        for(int r = 0 ; r<n ; r++){
            for( int c =0; c<n; c++){
            if(img2[r][c]==1){
            ones_img2.push_back({r,c});
            }
        }
        }
        map<pair<int, int>, int> shift_counts;
        int max_overlap = 0;
        for(auto& p1 : ones_img1) {

            for(auto& p2 : ones_img2) {
                int row_shift = p2.first - p1.first;
                int col_shift = p2.second - p1.second;
                
                pair<int, int> shift_vector = {row_shift, col_shift};

                shift_counts[shift_vector]++;
                max_overlap = max(max_overlap, shift_counts[shift_vector]);
            }
        }
        
        return max_overlap;
    }
};