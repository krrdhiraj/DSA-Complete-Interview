class Solution {
    int[] parent = new int[26];
    int[] rank = new int[26];
    int find(int a){
        if(a == parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }
    void Union(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b){
            return ;
        }
        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_a] = parent_b;
            rank[parent_b] += 1;
        }
    }
    public boolean equationsPossible(String[] equations) {
        for(int i = 0; i<26; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(String s : equations){
            if(s.charAt(1) == '='){
                Union(s.charAt(0) -'a', s.charAt(3)-'a');
            }
        }
        for(String s : equations){
            if(s.charAt(1) == '!'){
                int first = s.charAt(0)-'a';
                int second = s.charAt(3)-'a';

                int parent_first = find(first);
                int parent_second = find(second);

                if(parent_first == parent_second){
                    return false;
                }
            }
        }
        return true;
    }
}