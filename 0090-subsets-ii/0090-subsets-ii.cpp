class Solution {
public:
     void solve(vector<int>& nums,int ind,vector<int>&v,set<vector<int>>&ans,int n){
        if(ind==n){
            ans.insert(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(nums,ind+1,v,ans,n);
        v.pop_back();
        solve(nums,ind+1,v,ans,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        set<vector<int>>s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        solve(nums,0,v,s,n);
        for(auto i:s)
        ans.push_back(i);
        return ans;
    }
};