class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch : num){
            while(!st.empty() && k > 0 && (st.top()-'0') > (ch-'0')){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k-- > 0){
            st.pop();
        }
        if(st.empty())
            return "0";
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() != 0 && ans.back() == '0')
            ans.pop_back();
        if(ans.size() == 0)
            return "0";
            
        reverse(begin(ans), end(ans));
        return ans;
    }
};