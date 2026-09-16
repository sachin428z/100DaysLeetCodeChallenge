class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> rowMax(n,0);
        vector<int> colMax(n,0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                rowMax[i]=max(rowMax[i],grid[i][j]);
                colMax[j]=max(colMax[j],grid[i][j]);

            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int allowedHeight=min(rowMax[i],colMax[j]);
                ans+=allowedHeight-grid[i][j];
            }
        }
        return ans;
    }
};