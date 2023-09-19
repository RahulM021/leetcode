class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0,ans=i;
            while(ans){
                if(ans%2==1)
                cnt++;
                ans=ans/2;
            }
            if(cnt==k)
            sum=sum+nums[i];
        }
        return sum;
    }
};