class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char ch : s){
            if(ch >= 65 && ch <= 90 ){
                temp += (char)tolower(ch);
            }else if(ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57){
                temp += ch;
            }else{
                continue;
            }
        }
        int i = 0, j = temp.length()-1;
        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
};