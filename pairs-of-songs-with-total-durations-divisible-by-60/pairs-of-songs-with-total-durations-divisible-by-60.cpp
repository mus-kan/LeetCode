class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int ans=0;
        
        for(int i=0; i<time.size(); i++)
        {
           if(mp.find((600-time[i])%60)!=mp.end())
               ans+=mp[(600-time[i])%60];
            
            mp[time[i]%60]++;
        }
        
        return ans;
        
    
    }
};