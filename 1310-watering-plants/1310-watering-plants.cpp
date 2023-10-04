class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int k=capacity;
        for(int i=0;i<plants.size();i++){
            if(k>=plants[i]){
                ans=ans+1;
                k=k-plants[i];
            }
            else{
                k=capacity;
                k=k-plants[i];
                ans=ans+i*2+1;
            }
        }
        return ans;
    }
};