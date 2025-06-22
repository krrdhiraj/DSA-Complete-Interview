class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        int i = 0;
        while( i+k <= n){
            string temp = s.substr(i, k);
            ans.push_back(temp);
            i += k;
        }
        if(i < n){
            int sz = k - (n-i);
            string temp = s.substr(i);
            while(sz--){
                temp += fill;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};