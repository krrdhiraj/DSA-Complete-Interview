class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        vector<pair<char,int>> chars;
        for(auto it : mp){
            chars.push_back({it.first, it.second});
        }
        auto comp = [](pair<char,int> p1, pair<char,int> p2){
            return p1.second>p2.second;
        };
        sort(chars.begin(), chars.end(), comp);

        string ans ;
        for(auto p : chars){
            int freq = p.second;
            while( freq--){
                ans+= p.first;
            }
        }
        return ans;
    }
};