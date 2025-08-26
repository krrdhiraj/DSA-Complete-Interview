class Solution {
public:
    typedef pair<char,int> p;
    int beautySum(string s) {
        int n = s.length();

        int ans = 0;

        for(int i = 0; i<n; i++){
            unordered_map<char,int> mp;
            for(int j = i; j < n ;j++){
                mp[s[j]]++;
                int mxFreq = 0, mnFreq = INT_MAX;
                for(auto &it : mp){
                    mxFreq = max(mxFreq, it.second);
                    mnFreq = min(mnFreq, it.second);
                }
                ans += mxFreq - mnFreq;
            }
            
        }
        return ans;
    }
};