class Solution {
public:
    bool isHappy(int n) {
       if(n == 1 || n == 7)
            return true;
        
        int temp = n;
        while(temp > 9){
            
            string s = to_string(temp);
            long long sm = 0;
            for(int i = 0; i<s.length(); i++){
                int rem = s[i]-'0';
                sm += rem * rem;
            }
            if(sm == 1 || sm == 7)
                return true;
            temp = sm;
        }
        return false;
    }
};