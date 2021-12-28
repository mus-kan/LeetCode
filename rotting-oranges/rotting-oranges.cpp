class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<vector<int>>q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j,0});
            }
        }
        
        int minutes=0;
        
        while(!q.empty())
        {
            int i=q.front()[0];
            int j=q.front()[1];
            int time=q.front()[2];
            
            q.pop();
            
            minutes=time;
            
            
            if((i+1<m) && grid[i+1][j]==1)
            {
                q.push({i+1, j, time+1});
                grid[i+1][j]=2;
            }
            if((j+1<n) && grid[i][j+1]==1)
            {
                q.push({i, j+1, time+1});
                grid[i][j+1]=2;
            }
            
            if((i-1>=0) && grid[i-1][j]==1)
            {
                q.push({i-1, j, time+1});
                grid[i-1][j]=2;
            }
            if((j-1>=0) && grid[i][j-1]==1)
            {
                q.push({i, j-1, time+1});
                grid[i][j-1]=2;
            }
            
            
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return minutes;
    }
};