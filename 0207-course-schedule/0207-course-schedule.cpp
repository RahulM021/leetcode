class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses,0);
        queue<int> q;
        vector<int> v;
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<prerequisites.size();i++){
            ind[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0)
            q.push(i);
        }
        if(q.empty()) return false;
        else{
            while(!q.empty()){
                int node=q.front();
                q.pop();
                v.push_back(node);
                for(int it:adj[node]){
                    ind[it]--;
                    if(ind[it]==0)
                    q.push(it);
                }
            }
        }
        if(v.size()==numCourses) return true;
        return false;
        
    }
};