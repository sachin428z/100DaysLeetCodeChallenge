class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,int newColor,vector<vector<int>>& ans,int initCol) {

        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

    for(int k=0;k<4;k++) {
        int nrow=row+delrow[k];
        int ncol=col+delcol[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initCol && ans[nrow][ncol]!=newColor) 
        
        dfs(image,nrow,ncol,newColor,ans,initCol);
    }
}
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initCol = image[sr][sc];
        vector<vector<int>> ans=image;;

        dfs(image,sr,sc,newColor,ans,initCol);
        return ans;
    }
};
