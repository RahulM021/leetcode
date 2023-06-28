class Solution {
public:
    bool isThree(int n) {
           int i=1,c=0;
        while(i<=sqrt(n)){
            if( n%i==0){
                if(n/i!=i)c+=2;
                else c++;
            }
            i++;
        }
        cout<<c;
        return c==3;
    }
};