class NumberContainers {
public:
    unordered_map<int,int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx; // min-heap for storing the indices
    NumberContainers() {
        // already initialized
    }
    
    void change(int index, int number) {
        idxToNum[index] = number; // O(1)

        numToIdx[number].push(index); //O(1)
    }
    
    int find(int number) {
       
        auto& pq = numToIdx[number];
        while(!pq.empty()){ // size of pq = k => TC->{O(k * log(n))}
            int index = pq.top(); // o(1)
            if(idxToNum[index] == number){
                return index;
            }
            pq.pop(); // O(log(n))
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */