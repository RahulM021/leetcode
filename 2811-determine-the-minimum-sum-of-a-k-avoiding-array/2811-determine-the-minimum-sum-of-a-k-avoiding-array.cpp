class Solution {
public:
    int minimumSum(int n, int k) {
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=1;i<10e9;i++){
            if(k>i && mp.find(k-i)!=mp.end())
            continue;
            sum=sum+i;
            mp[i]=1;

            if(mp.size()==n)
            return sum;
        }
        return -1;
    }
};