class Solution {
public:
    bool dfs(vector<vector<int>> graph,vector<int> &vis,int src,int col){
        vis[src]=col;
        for(int i:graph[src]){
            if(vis[i]==-1){
            if(dfs(graph,vis,i,!col)==false)
            return false;
            }
            else if(vis[i]==col)
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(graph,vis,i,0)==false) 
                return false;
            }
        }
        return true;
    }
};