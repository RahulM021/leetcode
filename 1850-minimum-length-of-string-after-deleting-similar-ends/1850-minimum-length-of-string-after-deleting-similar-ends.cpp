class Solution {
public:
    int minimumLength(string st) {
        int s=0;
        int e=st.size()-1;
        while(s<e){
            if(st[s]!=st[e])
            return e-s+1;
            else if(st[s]==st[e]){
                if(st[s+1]==st[e] && s+1<e) s++;
                else if(st[s]==st[e-1] && s<e-1) e--;
                else {
                    s++;
                    e--;
                }
            }
        }
        if(s>e)
        return 0;
        else
        return 1;
    }
};