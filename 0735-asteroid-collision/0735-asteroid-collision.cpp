class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st; 
        vector<int> ans;
       
        for(int i = 0; i<n; i++){
           while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int sm = asteroids[i] + st.top();
                if(sm > 0){
                    asteroids[i] = 0;
                }else if(sm < 0){
                    st.pop();
                }else{
                    st.pop();
                    asteroids[i] = 0;
                }
           }
           if(asteroids[i] != 0)
                st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};