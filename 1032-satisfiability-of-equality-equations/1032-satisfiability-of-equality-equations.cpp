class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int a){
        if(a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }

    void Union(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b){
            return;
        }
        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        rank.resize(26,0);
        parent.resize(26);
        // fill the parent 
        for(int i = 0; i<26; i++){
            parent[i] = i;
        }
        for(string &s : equations){
            if(s[1] == '='){ // a == b -> Union krr do
            Union(s[0]-'a', s[3]-'a');
            }
        }
        // now a != b , check their validity
        for(string &s : equations){
            if(s[1] == '!'){
                int first = s[0]-'a';
                int second = s[3]-'a';

                int parent_first = find(first);
                int parent_second = find(second);

                if(parent_first == parent_second)
                    return false;
            }
        }
        return true;
    }
};