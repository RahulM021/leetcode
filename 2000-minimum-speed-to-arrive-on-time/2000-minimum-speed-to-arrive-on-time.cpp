class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1;
        int hi=1e7;
        double sum=0;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            sum=0;
            for(int i=0;i<dist.size();i++){
                if(i==dist.size()-1)
                sum=sum+(dist[i]*1.0/mid);
                else
                sum=sum+ceil(dist[i]*1.0/mid);
                
            }
            cout<<sum<<" ";
            if(sum<=hour){
            hi=mid-1;
            ans=mid;
            }
            else
            lo=mid+1;
        }
        return ans;
    }
};