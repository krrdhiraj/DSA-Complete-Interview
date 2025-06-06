class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int remainChar = n - (numFriends - 1);

        string ans ;
        for(int i = 0; i<n; i++){
            int possibleLength = min(remainChar, n-i);
            ans = max(ans, word.substr(i,possibleLength));
        }

        return ans;
    }
};