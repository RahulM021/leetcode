class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(dp[i][j]) return dp[i][j];
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        int l=0,r=0;
        if(i>0)
        l=solve(i-1,j,obstacleGrid,dp);
        if(j>0)
        r=solve(i,j-1,obstacleGrid,dp);
        return dp[i][j]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int ans=solve(m-1,n-1,obstacleGrid,dp);
        return ans;
    }
};