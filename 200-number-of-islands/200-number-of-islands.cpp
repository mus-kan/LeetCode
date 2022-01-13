//  class DSU
//     {
//         private:
//         vector<int>parent, size;
//         DSU(int n)
//         {
//             for(int i=0; i<n; i++)
//             {
//                 parent.push_back(i);
//                 size.push_back(i);
//             }
//         }
        
//         public:
//         int findPar(int node)
//         {
//             if(parent[node]==node)
//             {
//                 return node;
//             }
//             return parent[node]=findpar(parent[node]);
//         }
        
//         void union(int u, int v)
//         {
//             int pu=findPar(u);
//             int pv=findPar(v);
            
//             if(pu==pv)
//                 return ;
//             if(size(pu)<size(pv))
//             {
//                 parent[pu]=pv;
//                 size[pv]+=size[pu];
//             }
//             else
//             {
//                 parent[pv]=pu;
//                 size[pu]+=pv;
//             }
//         }
//     };
    

class Solution {
public:
    
    void dfs(vector<vector<char>>&grid, int i, int j, int m, int n)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
        {
            return;
        }
        
        grid[i][j]='0';
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        
    }
   
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        // int newarr[m*n];
        // for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         newarr[n*i+j]=grid[i][j];  //converting to one-D array
        //     }
        // }
        
        int count=0; 
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return count;
        
        
    }
};