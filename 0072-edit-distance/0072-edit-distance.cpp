class Solution {
public:
    int solve(int m,int n,string word1, string word2,vector<vector<int>> &dp){
        // if(i<0)
        // return j+1;
        // if(j<0)
        // return i+1; 
        // if(dp[i][j]!=-1)
        // return dp[i][j];
        
        for(int i=0;i<=m;i++)
        dp[i][0]=i;
        for(int j=0;j<=n;j++)
        dp[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        return dp[m][n];
        // if(word1[i]==word2[j])
        // return dp[i][j]=0+solve(i-1,j-1,word1,word2,dp);
        // else{
        //     int in=solve(i-1,j,word1,word2,dp);
        //     int de=solve(i,j-1,word1,word2,dp);
        //     int re=solve(i-1,j-1,word1,word2,dp);
        //     return dp[i][j]=1+min(in,min(de,re));
        // }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        int ans=solve(m,n,word1,word2,dp);
        return ans;
    }
};