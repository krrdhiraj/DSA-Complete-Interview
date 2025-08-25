class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> st = new HashSet<>();

        while(true){

            int sm = 0;
            // sum of squares of digit
            while(n > 0){
                sm += Math.pow(n%10, 2);
                n = n/10;
            }

            if(sm == 1)
                return true;
            n = sm;
            if(st.contains(sm)){
                return false;
            }
            
            st.add(sm);
        }
        // return false;
    }
}