class Solution {
public:
    int solve(string text1,string text2,int m,int n,vector<vector<int>> &dp){

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string t1=s;
        reverse(s.begin(),s.end());
        string t2=s;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1));
        int ans=solve(t1,t2,s.size(),s.size(),dp);
        return ans;
    }
};