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
        int start = 0, end = 0;
        while(i < n){
            end = max(end, mp[s[i]-'a']);
            if( i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return ans;
    }
};