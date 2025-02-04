// code for DSU {Union & Find}

// find their parent
  int find(int u, vector<int>& parent){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u], parent);
    }
    
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);
        if(parent_x == parent_y){ // found cycle
            return ;
        }
        if(rank[parent_x] > rank[parent_y]){ // jiska rank jyada usko parent banao
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{ // rank equal :-> kisi ek ko parent bana do or uska rank + 1 kar do
            parent[parent_x] = parent_y;
            rank[parent_y] +=1;
        }
    }
