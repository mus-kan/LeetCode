class Solution {
public:
    bool recursive_engine(string &s, string &p,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool output;
        if(i==s.length()){
            output= ((j==p.length()) || (p[j]=='*' && recursive_engine(s,p,i,j+1,dp)));
            
        }
        else if(p[j]=='*'){
            output= recursive_engine(s,p,i+1,j,dp) || recursive_engine(s,p,i,j+1,dp);
        }
        else{
            if(s[i]==p[j] || p[j]=='?'){
                output= recursive_engine(s,p,i+1,j+1,dp);
            }
            else output= false;
        }
        dp[i][j]=output;
        return output;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        return recursive_engine(s,p,0,0,dp);
    }
    
};