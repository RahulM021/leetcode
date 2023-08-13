class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp,vector<vector<int>> grid){
        // if(i==0 && j==0) return grid[0][0];
        // if(dp[i][j]) return dp[i][j];
        // int l=INT_MAX,r=INT_MAX;
        // if(i>0)
        // l=solve(i-1,j,dp,grid);
        // if(j>0)
        // r=solve(i,j-1,dp,grid);

        // return dp[i][j]=grid[i][j]+min(l,r);
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                dp[i][j]=grid[i][j];
                else{
                int l=INT_MAX,r=INT_MAX;
                if(i>0)
                l=dp[i-1][j];
                if(j>0)
                r=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(l,r);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int ans=solve(m-1,n-1,dp,grid);
        return ans;
    }
};