class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = INT_MIN;
        for(int val : piles){
            mx = max(mx, val);
        }
        int l = 1; 
        int r = mx;
        while(l <= r){
            int mid = (r+l)/2;
            long sm = 0;
            for(int i = 0; i<n; i++){
                sm += ceil((double)piles[i]/ (double)mid);
            }
            if(sm <= h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};