class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis) {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

        for(int k = 0; k < 4; k++) {
    

                int neighRow=row+delRow[k];
                int neighCol=col+delCol[k];
                if(neighRow>=0 && neighRow<n && neighCol>=0 && neighCol<m && grid[neighRow][neighCol]=='1' && !vis[neighRow][neighCol]) {
                vis[neighRow][neighCol]=1;
                q.push({neighRow,neighCol});
                }
            }
        }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};    