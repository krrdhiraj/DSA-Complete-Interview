/* 
    Leetcode Link               : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force - Trying All Possibilities)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    ans = max(ans, (long long)(nums[i] - nums[j])*nums[k]);
                }
            }
        }

        return ans;
    }
};


//Approach-2 (Using prefix and suffix storage)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return ans;
    }
};


//Approach-3 (Keeping track of maxDif and maxi)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        long long maxDiff = 0;
        long long maxI = 0;

        for(int k = 0; k < n; k++) {
            ans = max(result, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxI - nums[k]);
            maxI = max(maxI, (long long)nums[k]);
        }
        return ans;
    }
};



/*************************************************************** JAVA ***************************************************************/
// Approach-1 (Brute Force - Trying All Possibilities)
// T.C : O(n^3)
// S.C : O(1)
class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = Math.max(ans, (long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        
        return ans;
    }
}

// Approach-2 (Using prefix and suffix storage)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], nums[i + 1]);
        }
        
        long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            ans = Math.max(ans, (long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        
        return ans;
    }
}

// Approach-3 (Keeping track of maxDiff and maxi)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long ans = 0;
        long maxDiff = 0;
        long maxI = 0;
        
        for (int k = 0; k < n; k++) {
            ans = Math.max(ans, maxDiff * nums[k]);
            maxDiff = Math.max(maxDiff, maxI - nums[k]);
            maxI = Math.max(maxI, nums[k]);
        }
        
        return ans;
    }
}
