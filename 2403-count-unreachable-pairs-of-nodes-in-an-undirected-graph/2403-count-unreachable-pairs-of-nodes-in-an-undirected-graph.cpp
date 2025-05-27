class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int a){
        if( a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }
    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb)
            return;
        if(rank[pa] > rank[pb]){
            parent[pb] = pa;
        }
        else if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }else{
            parent[pa] = pb;
            rank[pb] += 1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        // find total no of component
        for(auto &edge : edges){
            if(find(edge[0]) != find(edge[1])){
                Union(edge[0], edge[1]);
            }
        }
        // calculating no of nodes in each component and storing it in a map
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            int parent = find(i);
            mp[parent]++;
        }

        // calculating final ans -> size * (n - size)
        long long ans = 0;
        for(auto &it : mp){
            ans += it.second * (n-it.second);
            n -= it.second;
        }
        return ans;
    }
};