class Solution {
public:
    typedef pair<char,int> p;
    struct comp{
        bool operator()(p p1, p p2){
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<p, vector<p> , comp> pq;
        for(char ch : s){
            mp[ch]++;
        }
        for(auto it : mp){
            pq.push({it.first, it.second});
        }
        
        string ans ;
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();
            string t = string(temp.second,temp.first);
            ans += t;
        }
        return ans;
    }
};