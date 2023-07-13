class Solution {
public:
    void func(vector<int>& candidates,int index,int target,vector<int>&v, vector<vector<int>> &ans){
        if(target==0){
        ans.push_back(v);
        return;
        }
        if(index==candidates.size() || (target-candidates[index])<0)
        return;
        

        v.push_back(candidates[index]);
        func(candidates,index,target-candidates[index],v,ans);
        v.pop_back();
        func(candidates,index+1,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        func(candidates,0,target,v,ans);
        return ans;

    }
};