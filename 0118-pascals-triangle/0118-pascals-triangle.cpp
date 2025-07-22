class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i = 1;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);

        while(i < numRows){
            vector<int> v;
            v.push_back(1);
            for(int j = 0; j<temp.size()-1;j++){
                v.push_back(temp[j]+temp[j+1]);
            }
            v.push_back(1);
            ans.push_back(v);
            temp = v;
            i++;
        }
        return ans;
    }
};