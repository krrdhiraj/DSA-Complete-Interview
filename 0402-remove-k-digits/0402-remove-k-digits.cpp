class Solution {
public:
    string removeKdigits(string num, int k) {
         string st;
        for(char ch : num){
            while(st.length() > 0 && k > 0 && st.back() > ch){
                st.pop_back();
                k--;
            }
            if(st.length() > 0 || ch != '0')
                st.push_back(ch);
        }
        while(st.length() > 0 && k > 0){
            k -= 1;
            st.pop_back();
        }
        if(st.length() == 0)
            return "0";
        
        return st;
    }
};