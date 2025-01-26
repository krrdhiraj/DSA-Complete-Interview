class Solution {
public:
    int romanToInt(string s) {
        // store all the roman symbol with their respective value
        unordered_map<char,int> um{{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        int n = s.length();
        int ans = 0;
        // Now traverse the string and find their integer value
        for(int i = 0; i<n; i++){
            if(i+1 < n &&  um[s[i]] < um[s[i+1]]){
                ans += um[s[i+1]]-um[s[i]];
                i++;
            }else{
                ans += um[s[i]];
            }
        }
        return ans;
    }
};