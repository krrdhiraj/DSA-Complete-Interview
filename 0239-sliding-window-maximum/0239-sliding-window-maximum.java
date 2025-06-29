class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];
        int idx = 0;
        int i = 0, j = 0;
        Deque<Integer> dq = new ArrayDeque<>();

        while(j < n){
            while(!dq.isEmpty() && nums[j] > dq.peekLast()){
                dq.pollLast();
            }

            dq.add(nums[j]);

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                ans[idx++] = dq.peek();

                if(nums[i] == dq.peek()){
                    dq.pollFirst();
                }
                i++;
                j++;
            }
        }
        return ans;

    }
}