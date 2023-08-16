class Solution {
public:
    int digit(int val){
        int ans=INT_MIN;
        while(val!=0){
            int rem=val%10;
            ans=max(ans,rem);
            val=val/10;
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(digit(nums[i])==digit(nums[j]))
                ans=max(ans,nums[i]+nums[j]);
            }
        }
        return ans;
    }
};