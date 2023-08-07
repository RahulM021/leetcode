class Solution {
public:
    void solve(string tiles,string s,vector<int> &f,unordered_set<string> &ans){
        for(int i=0;i<tiles.size();i++){
            if(f[i]==0){
                s=s+tiles[i];
                f[i]=1;
                ans.insert(s);
                solve(tiles,s,f,ans);
                s.pop_back();
                f[i]=0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> f(tiles.size(),0);
        unordered_set<string> ans;
        solve(tiles,"",f,ans);
        return ans.size();
    }
};