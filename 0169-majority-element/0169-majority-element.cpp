class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
        int maj = 0;
        int count = 0;
        for(int num : nums){ // Boyer Moore voting
            if(num == maj){
                count++;
            }else if(count == 0){
                maj = num;
                count = 1;
            }else{
                count--;
            }
        }
        return maj;
    }
};