class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> ans;

        unordered_map<char,int> mp; // storing last index of a char
        for(int i = 0; i<n; i++){
            mp[s[i]-'a'] = i;
        }

        int i = 0;
        while(i < n){
            int end = mp[s[i]-'a'];

            int j = i;
            while(j < end){
                end = max(end, mp[s[j]-'a']);
                j++;
            }
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        return ans;
    }
};