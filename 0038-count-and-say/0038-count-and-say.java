class Solution {
    public String countAndSay(int n) {
        if(n == 1)
            return "1";

        String say = countAndSay(n-1);

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<say.length(); i++){
            int cnt = 1;
            char ch = say.charAt(i);
            while(i< say.length()-1 && say.charAt(i) == say.charAt(i+1)){
                cnt++;
                i++;
            }
            sb.append(cnt).append(ch);
        }
        return sb.toString();
    }
}