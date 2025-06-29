class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        int n = nums.length;
        int[] ans = new int[n-k+1];
        int j = 0;

        Deque<Integer> dq = new ArrayDeque<>();

        for(int i = 0; i<n; i++){
            // step 1 : make space for new element
            while(!dq.isEmpty() && dq.peek() <= i-k){ // window size se jayada element h, remove it
                dq.pollFirst();
            }
            // step 2 : nums[i] > elemnts present at back of deque
            while(!dq.isEmpty() && nums[i] > nums[dq.peekLast()]){
                dq.pollLast();
            }
            // step 3: add new element to the deque
            dq.offer(i);

            // step 4 : window size completed now store ans from dq.getFirst
            if(i >= k-1){
                ans[j++] = nums[dq.peek()];
            }
        }
        return ans;

    }
}