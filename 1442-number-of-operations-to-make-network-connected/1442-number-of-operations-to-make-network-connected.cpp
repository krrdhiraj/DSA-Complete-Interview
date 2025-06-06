class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int a){
        if(a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }
    void Union(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b)
            return;
        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_a] = parent_b;
            rank[parent_b] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if(sz < n-1)
            return -1;
        parent.resize(n);
        rank.resize(n,1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        for(auto &it : connections){
            int parent_first = find(it[0]);
            int parent_second = find(it[1]);

            if(parent_first != parent_second){
                Union(it[0], it[1]);
                n--;
            }
        }
        return n-1;
    }
};