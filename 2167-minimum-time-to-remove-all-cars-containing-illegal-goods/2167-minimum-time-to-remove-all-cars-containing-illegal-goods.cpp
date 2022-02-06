class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        
        if(s[n-1]=='0')
            dp[n-1]=0;
        else
        {
            dp[n-1]=1;
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(s[i]=='0')
                dp[i]=dp[i+1];
            else
            {
                dp[i]=min(2+dp[i+1], n-i);
            }
        }
        
        int res=dp[0];
        for(int i=0; i<n-1; i++)
        {
            res=min(res, i+1+dp[i+1]);
        }
        
        // res=min(res,n);
        
        return res;
    }
};