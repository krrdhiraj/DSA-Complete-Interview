class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if( n == 0)
            return "";
        string common = strs[0];
        
        for(int i = 0; i < common.length(); i++){
            for(int j = 1; j<n; j++){

                if(i == strs[j].length() || strs[j][i] != common[i]){
                    return common.substr(0,i);
                }
            }
        }
        return common;
    }
};