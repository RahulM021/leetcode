class Solution {
public:
    bool isThree(int n) {
        int cnt=1;
        for(int i=2;i<=n;i++)
        if(n%i==0)
        cnt++;

        return cnt==3;
    }
};