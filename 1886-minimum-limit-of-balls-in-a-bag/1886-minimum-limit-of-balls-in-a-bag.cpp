class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid){
                    if(nums[i]%mid==0)
                    cnt=cnt+(nums[i]/mid)-1;
                    else
                    cnt=cnt+(nums[i]/mid);
                }
            }
            if(cnt<=maxOperations){
                ans=mid;
            hi=mid-1;
            }
            else
            lo=mid+1;
        }
        return lo;
    }
};