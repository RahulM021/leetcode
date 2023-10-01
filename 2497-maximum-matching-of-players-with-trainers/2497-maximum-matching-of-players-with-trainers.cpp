class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0;
        int ind=0;
        for(int i=0;i<players.size();i++){
            for(int j=ind;j<trainers.size();j++){
                if(players[i]<=trainers[j]){
                    cnt++;
                    ind=j+1;
                    break;
                }
            }
        }
        return cnt;
    }
};