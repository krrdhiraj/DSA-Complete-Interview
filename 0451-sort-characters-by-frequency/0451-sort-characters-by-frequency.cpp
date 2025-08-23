class Solution {
public:
    typedef pair<char,int> p;
    string frequencySort(string s) {
        vector<p> mp(123);
        for(char ch : s){
           mp[ch] = {ch,mp[ch].second+1};
        }

        auto comp = [](pair<char,int> p1, pair<char,int> p2){
            return p1.second>p2.second;
        };
        sort(mp.begin(), mp.end(), comp);

        string ans ;
        for(auto pr : mp){
            int freq = pr.second;
            string t = string(freq,pr.first);
            ans += t;
        }
        return ans;
    }
};