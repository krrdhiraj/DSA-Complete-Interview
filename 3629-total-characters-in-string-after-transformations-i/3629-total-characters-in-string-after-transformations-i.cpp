class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);
        for(char ch : s){
            mp[ch-'a']++;
        }
        for(int i = 0; i<t; i++){
            vector<int> temp(26,0);
            for(int i = 0; i<26; i++){
                char ch = i + 'a';
                int freq = mp[i];
                if(ch == 'z'){
                    temp['a'-'a'] = (temp['a'-'a'] + freq) % M;
                    temp['b'-'a'] = (temp['b'-'a'] + freq) % M;
                }else{
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a'] + freq) % M;
                }
            }
            mp = move(temp);
        }
        int cnt = 0;
        for(int i = 0; i<26; i++){
            cnt = (cnt + mp[i])% M;
        }
        return cnt;
    }
};