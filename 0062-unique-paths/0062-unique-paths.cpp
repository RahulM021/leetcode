class Solution {
public:
    int count(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        return 0;
         
        if(dp[i][j]!=-1)
        return dp[i][j];
        int l=count(i-1,j,dp);
        int r=count(i,j-1,dp);
        return dp[i][j]=l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=count(m-1,n-1,dp);
        return ans;
    }
};