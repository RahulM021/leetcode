class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> ind(n+1,0);
        vector<int> oud(n+1,0);

        for(int i=0;i<trust.size();i++){
            oud[trust[i][0]]++;
            ind[trust[i][1]]++;
        }

        for(int i=0;i<=n;i++){
            if(ind[i]==n-1 && oud[i]==0)
            return i;
        }
        return -1;
    }
};