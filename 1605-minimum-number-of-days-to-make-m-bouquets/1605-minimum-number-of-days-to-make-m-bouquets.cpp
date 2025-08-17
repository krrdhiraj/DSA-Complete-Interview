class Solution {
public:
    int find(vector<int>& bloomDay, int day, int k){
         int bouqet = 0;
         int cnt = 0;
            for(int i = 0; i<bloomDay.size(); i++){
                if(day >= bloomDay[i]){
                    cnt++;
                }else{
                    cnt = 0;
                }
                if(cnt == k){
                    cnt = 0;
                    bouqet++;
                }
            }
            return bouqet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int mx = *max_element(begin(bloomDay), end(bloomDay));
        if(n < (long long)m*(long long)k)
            return -1;
        int l = 1, h = mx;
        while( l <= h){
            int mid = (l+h)/2;
            int noOfBouq = find(bloomDay, mid, k);

            if(noOfBouq < m){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return l;
    }
};