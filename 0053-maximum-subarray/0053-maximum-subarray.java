class Solution {
    public int maxSubArray(int[] nums) {
        int sm = Integer.MIN_VALUE;
        int n = nums.length;
        int currSm = 0;
        int startIndx = -1, endIndx = -1;
        int start = -1;
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i<n ;i++){
            if(currSm == 0){
                start = i;
            }
            currSm += nums[i];

            if(currSm > sm){
                sm = currSm;
                startIndx = start;
                endIndx = i;
            }
            if(currSm < 0){
                currSm = 0;
            }
        }
        while(startIndx <= endIndx){
            list.add(nums[startIndx]);
            startIndx++;
        }
        System.out.println(list);
        return sm;
    }
}