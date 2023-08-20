class Solution {
public:
    long long int solve(int i,int j,vector<vector<int>> matrix,vector<vector<int>> &dp){
        if(j<0 || j>=matrix.size())
        return INT_MAX;
        if(i==0)
        return matrix[0][j];
        if(dp[i][j]!=-1)
        return dp[i][j];

        int u=solve(i-1,j,matrix,dp);
        int dl=solve(i-1,j-1,matrix,dp);
        int dr=solve(i-1,j+1,matrix,dp);

        return dp[i][j]=matrix[i][j]+min(u,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        dp[0][j]=matrix[0][j];
        int r,c;
        int u,dl,dr;
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                u=dp[i-1][j];
                dl=INT_MAX;
                if(j-1>=0) dl=dp[i-1][j-1];
                dr=INT_MAX;
                if(j+1<m) dr=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(u,min(dl,dr));
                }
            }
            for(int j=0;j<m;j++){
                ans=min(ans,dp[n-1][j]);
            }

        return ans;
    }
};