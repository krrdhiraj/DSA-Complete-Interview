class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j <n ; j++){
                for(int k = 0; k<n; k++){
                    if(i == j || j == k || i == k)
                        continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num > 99 && num % 2 == 0){
                        ans.insert(num);
                    }
                }
            }
        }
       vector<int> res(begin(ans), end(ans));
       return res;
    }
};