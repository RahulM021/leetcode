class Solution {
public:
    int solve(int ind,vector<int> nums,vector<int> &dp){
        if(ind>=nums.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];

        int not_take=solve(ind+1,nums,dp);
        int take=INT_MIN;
        take=nums[ind]+solve(ind+2,nums,dp);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=solve(0,nums,dp);
        return ans;
    }
};