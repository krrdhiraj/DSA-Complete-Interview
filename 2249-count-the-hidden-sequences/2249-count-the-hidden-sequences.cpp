class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int curr = 0;
        int maxVal = 0, minVal = 0;
        int cnt = 0;
        for(int &d : diff){
            curr = curr + d;

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper - maxVal) - (lower-minVal)+1 <= 0){
                return 0;
            }
        }
        return (upper - maxVal) - (lower-minVal)+1;
    }
};