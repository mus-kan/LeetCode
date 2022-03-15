class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        const int inf = 1e9;
        vector<int> dist(n+1,inf);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto node=pq.top();
            int dis=node.first;
            int ver=node.second;
            pq.pop();
            for(auto it: adj[ver]){
                int nextnode=it.first;
                int nextdist=it.second;
                if(dist[nextnode] > dist[ver]+nextdist)
                   {
                    dist[nextnode]=dist[ver]+nextdist;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        int flag=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==inf){
                flag=1;
            }
        }
        if(flag==1){
            return -1;
        }
        else{
          for(int i=1;i<=n;i++){
              ans=max(ans,dist[i]);
          }  
        }
        return ans;
    }
};