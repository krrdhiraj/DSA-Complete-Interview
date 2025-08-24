class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> mp{{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M', 1000} };
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'I' && i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X')){
                ans += mp[s[i+1]]-mp[s[i]];
                i++;
            }else if(s[i] == 'X' && i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C' )){
                ans += mp[s[i+1]]-mp[s[i]];
                i++;
            }else if(s[i] == 'C' && i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M')){
                ans += mp[s[i+1]]-mp[s[i]];
                i++;
            }else{
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};