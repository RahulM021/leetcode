class Solution {
public:
    void func(vector<int>& candidates,int index,int target,vector<int>&v, vector<vector<int>> &ans){
        if(index==candidates.size()){
        if(target==0){
        ans.push_back(v);
        }
        return;
        }
        
        if(candidates[index]<=target){
        v.push_back(candidates[index]);
        func(candidates,index,target-candidates[index],v,ans);
        v.pop_back();
        }
        func(candidates,index+1,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        func(candidates,0,target,v,ans);
        return ans;

    }
};