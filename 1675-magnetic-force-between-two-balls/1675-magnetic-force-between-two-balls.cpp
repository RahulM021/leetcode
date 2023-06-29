class Solution {
public:
    bool place(vector<int>& a,int m,int d){
        int cur=a[0];
        m--;
        for(int i=1;i<a.size();i++){
            if((a[i]-cur)>=d){
                m--;
                cur=a[i];
                if(m==0)
                return true;
            }
        }
        return m==0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo=1;
        int hi=*max_element(position.begin(),position.end());
        int ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(place(position,m,mid)){
                ans=mid;
            lo=mid+1;
            }
            else
            hi=mid-1;
        }
        return hi;
    }
};