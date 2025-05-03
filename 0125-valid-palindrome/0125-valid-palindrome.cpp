class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if( n == 0)
            return true;
        
        int i = 0, j = n-1;
        while(i <= j){
            char firstCh = s[i];
            char lastCh = s[j];
            if(!isalnum(firstCh)){
                i++;
                continue;
            }
            if(!isalnum(lastCh)){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++;j--;
            }
        }
        return true;
    }
};