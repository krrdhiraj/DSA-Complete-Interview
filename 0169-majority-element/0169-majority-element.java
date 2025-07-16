class Solution {
    // Tc -> O(n)
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int maj = 0;
        int count = 0;
        for(int num : nums){ // Boyer Moore voting
            if(count == 0){
                maj = num;
                count = 1;
            }else if(num == maj){
                count++;
            }else{
                count--;
            }
        }
        return maj;
    }
}