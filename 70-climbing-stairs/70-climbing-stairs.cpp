class Solution {
public:
    int climbStairs(int n) {
//         int dp[n+1];
//         dp[0]=1;
//         dp[1]=1;
//         for(int i=2; i<n+1; i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
        int prev2=1;
        int prev=1;
        
        for(int i=2; i<n+1; i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        
        return prev;
    }
};