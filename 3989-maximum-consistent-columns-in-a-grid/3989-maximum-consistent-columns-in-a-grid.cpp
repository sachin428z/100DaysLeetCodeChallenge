class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(n,1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                bool ok=true;
                for(int k=0;k<m;k++) {
                    if(abs(grid[k][j]-grid[k][i])>limit) {
                        ok=false;
                        break;
                    }
                }
                if(ok) {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }

        int res=0;
        for(int i=0;i<n;i++) {
            res=max(res,dp[i]);
        }
        return res;

    }
};