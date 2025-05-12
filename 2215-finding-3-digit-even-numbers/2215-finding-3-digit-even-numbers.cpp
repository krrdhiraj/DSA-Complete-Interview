class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j <n ; j++){
                for(int k = j+1; k<n; k++){
                    if(digits[i] != 0){
                        int num1 = digits[i]*100 + digits[j]*10+ digits[k];
                        int num2 = digits[i]*100 + digits[k]*10+ digits[j];
                        if(num1 % 2 == 0){
                            ans.insert(num1);
                        }if(num2 % 2 == 0){
                            ans.insert(num2);
                        }
                    }if(digits[j] != 0){
                        int num1 = digits[j]*100 + digits[i]*10+ digits[k];
                        int num2 = digits[j]*100 + digits[k]*10+ digits[i];
                        if(num1 % 2 == 0){
                            ans.insert(num1);
                        }if(num2 % 2 == 0){
                            ans.insert(num2);
                        }
                    }
                    if(digits[k] != 0){
                        int num1 = digits[k]*100 + digits[i]*10+ digits[j];
                        int num2 = digits[k]*100 + digits[j]*10+ digits[i];
                        if(num1 % 2 == 0){
                            ans.insert(num1);
                        }if(num2 % 2 == 0){
                            ans.insert(num2);
                        }
                    }
                }
            }
        }
       vector<int> res(begin(ans), end(ans));
       return res;
    }
};