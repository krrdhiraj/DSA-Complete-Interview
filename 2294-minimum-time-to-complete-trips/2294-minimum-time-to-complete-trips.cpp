class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         int n = time.size();
        int minTime = INT_MAX;
        for(int val : time){
            minTime = min(val, minTime);
        }
        long long l = 1; 
        long long r =((long long)minTime*(long long)totalTrips);
        while(l <= r){
            long long mid = (r+l)/2;
            long long currSm = 0;
            for(int i = 0; i<n; i++){
                currSm += mid/time[i];
            }
            
            if(currSm < totalTrips){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};