class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind>=prices.size())
        return 0;
        if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        int profit=0;

        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,prices,cap,dp),0+solve(ind+1,1,prices,cap,dp));
        }
        else{
            profit=max(prices[ind]+solve(ind+1,1,prices,cap-1,dp),0+solve(ind+1,0,prices,cap,dp));
        }
        
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=solve(0,1,prices,2,dp);
        return ans;
    }
};