class Solution {
public:
    int solve(int ind,int amount,vector<int> a,vector<vector<int>> &dp){
        //if(amount==0) return 1;
        if(ind==0){
            if(amount%a[0]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        int take=0,nottake=0;
        if(amount>=a[ind])
        take=solve(ind,amount-a[ind],a,dp);
        nottake=solve(ind-1,amount,a,dp);
        return dp[ind][amount]=take+nottake;
        //return take+nottake;

    }
    int change(int amount,vector<int> &coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);

        // for(int i=0;i<coins.size();i++)
        // dp[i][0]=0;
        // if(coins[0]<=amount)
        // dp[0][coins[0]]=1;

        // for(int i=1;i<coins.size();i++){
        //     for(int j=1;j<=amount;j++){
        //         if(j>=coins[i])
        //         dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
        //     }
        // }
        // return dp[coins.size()-1][amount];

        return ans;
    }
};