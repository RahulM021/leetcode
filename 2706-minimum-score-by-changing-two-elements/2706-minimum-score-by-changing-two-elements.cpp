class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        vector<int> v;
        v=nums;
        sort(v.begin(),v.end());
        int case1=abs(v[v.size()-1]-v[2]);
        int case2=abs(v[v.size()-3]-v[0]);
        int case3=abs(v[v.size()-2]-v[1]);
        return min(case1,min(case2,case3));
    }
};