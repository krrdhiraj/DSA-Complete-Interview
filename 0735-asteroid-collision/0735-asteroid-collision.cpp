class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;
       
        for(int i = 0; i<n; i++){
           while(!st.empty() && asteroids[i] < 0 && st.back() > 0){
                int sm = asteroids[i] + st.back();
                if(sm > 0){
                    asteroids[i] = 0;
                }else if(sm < 0){
                    st.pop_back();
                }else{
                    st.pop_back();
                    asteroids[i] = 0;
                }
           }
           if(asteroids[i] != 0)
                st.push_back(asteroids[i]);
        }
        
        return st;
    }
};