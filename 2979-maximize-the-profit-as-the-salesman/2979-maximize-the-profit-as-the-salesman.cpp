class Solution {
public:
    int bn_s(int ind,vector<vector<int>> &offers){
        int s,e,mid;
        s=ind+1;
        e=offers.size()-1;
        int ans=offers.size()+1;
        while(s<=e){
            mid=(s+e)/2;
            if(offers[mid][0]>offers[ind][1]){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }    
    
    int solve(int ind,int n,vector<vector<int>>&offers,vector<int> &dp){
        if(ind>=offers.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int next_ind=bn_s(ind,offers);
        int not_take=solve(ind+1,n,offers,dp);
        int take=offers[ind][2]+solve(next_ind,n,offers,dp);

        return dp[ind]=max(take,not_take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size(),-1);
        int ans=solve(0,n,offers,dp);

        // for(int i=offers.size()-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int not_take=dp[i+1][j+1];
        //         int take=INT_MIN;
        //         if(j==-1 || offers[i][0]>offers[j][1])
        //         take=offers[i][2]+dp[i+1][i+1];
        //         dp[i][j+1]=max(take,not_take);
        //     }
        // }
        // return dp[0][0];

        return ans;
    }
};