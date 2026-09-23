class Solution {
public:
int findMax(vector<int> piles){
        int n = piles.size();
        int maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
long long totalHour( vector<int> &piles, int speed){
    long long TH=0;
    int n = piles.size();
    for(int i =0;i<n;i++){
       TH += (piles[i] + (long long)speed - 1) / speed;
    }
    return TH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalhour = totalHour( piles, mid);
            if(totalhour<=h){
                 high = mid-1;
                
            }
            else {
           low = mid +1;
    }
        }
        return low;
        }
};