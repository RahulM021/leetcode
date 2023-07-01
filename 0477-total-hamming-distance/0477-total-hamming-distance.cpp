class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size()==1)
        return 0;
        int ans=0;
        int cntones=0;
        int cntzeros=0;
        for(int i=0;i<32;i++){
            cntones=0;
            cntzeros=0;
            for(int j=0;j<nums.size();j++){
                if(((nums[j]>>i)&1))
                cntones++;
                else
                cntzeros++;
            }
            ans=ans+(cntones*cntzeros);
        }
        return ans;
    }
};