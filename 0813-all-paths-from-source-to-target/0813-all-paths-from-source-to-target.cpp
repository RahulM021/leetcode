class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,int src,vector<int> &v){
        if(src==graph.size()-1){
            v.push_back(src);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(src);
        for(int i:graph[src]){
            dfs(graph,ans,i,v);
        }
        v.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> vis(graph.size(),0);
        vector<int> v;
        dfs(graph,ans,0,v);
        return ans;
    }
};