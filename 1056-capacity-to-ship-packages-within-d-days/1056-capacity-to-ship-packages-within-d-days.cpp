class Solution {
public:
    int find(vector<int>& weights, int cap){
        int days = 1, load = 0;
        for(int i = 0; i<weights.size(); i++){
            if(load + weights[i] > cap){
                load = weights[i];
                days++;
            }else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights), end(weights));

        int h = accumulate(begin(weights), end(weights), 0);
        while(l <= h){
            int mid = (l+h)/2;
            int daysReq = find(weights, mid);
            if(daysReq <= days){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};