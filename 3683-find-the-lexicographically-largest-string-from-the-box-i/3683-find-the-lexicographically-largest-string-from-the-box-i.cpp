class Solution {
public:
    int bestSplitPoint(string word, int n){
        int i = 0; 
        int j = 1;

        while(j < n){
            int k = 0;
            while(j + k < n && word[j+k] == word[i+k]){
                k++;
            }
            if(word[j+k] > word[i+k]){
                i = j;
                j = j+1;
            }else{
                j  = j + k + 1;
            }
        }
        return i ;
    }
    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int possibleLen = n - (numFriends - 1);

        string ans ;
        int i = bestSplitPoint(word, n);
       
        int possibleLength = min(possibleLen, n-i);
        ans = max(ans, word.substr(i,possibleLength));
        

        return ans;
    }
};