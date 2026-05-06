class Solution {
    // Optimal Approach : O(n)
    public int subarraySum(int[] nums, int k) {
       int n = nums.length;
       // we will use prefix sum here {preSum[j]-preSum[i] = k} => {preSum[i] = preSum[j]-k}

       HashMap<Integer,Integer> mp = new HashMap<>();

       // put {0,1}==> if sum = 0 then freq = 1;
       mp.put(0,1);
        int preSum = 0;
        int res = 0;
       for(int val : nums){
            preSum += val;

            if(mp.containsKey(preSum - k)){
                res += mp.get(preSum - k);
            }
            mp.put(preSum, mp.getOrDefault(preSum, 0)+1);
       }
       return res;

    }
}