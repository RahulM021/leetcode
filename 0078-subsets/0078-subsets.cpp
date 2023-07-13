class Solution {
public:
    void solve(vector<int>& nums,int ind,vector<int>&v,vector<vector<int>>&ans,int n){
        if(ind>n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(nums,ind+1,v,ans,n);
        v.pop_back();
        solve(nums,ind+1,v,ans,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size()-1;
        solve(nums,0,v,ans,n);
        return ans;
    }
};