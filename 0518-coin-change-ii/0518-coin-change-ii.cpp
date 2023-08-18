class Solution {
public:
    int solve(int ind,int amount,vector<int> a,vector<vector<int>> &dp){
        if(amount<0) return 0;
        if(ind<0){
            if(amount==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];

        int take=solve(ind,amount-a[ind],a,dp);
        int nottake=solve(ind-1,amount,a,dp);
        return dp[ind][amount]=take+nottake;

    }
    int change(int amount,vector<int> &coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        return ans;
    }
};