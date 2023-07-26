class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n==1) return {0};
        queue<int> q;
        vector<int> ind(n,0);
        vector<int> adj[n];

        for(int i=0;i<edges.size();i++){
            ind[edges[i][0]]++;
            ind[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(ind[i]==1)
            q.push(i);
        }
        while(!q.empty()){
            ans={};
            int s=q.size();
            while(s--){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(int it:adj[node]){
                    ind[it]--;
                    if(ind[it]==1)
                    q.push(it);
                }
            }
        }
        return ans;

    
    }
};