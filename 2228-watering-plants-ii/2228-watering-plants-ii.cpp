class Solution
{
    public:
        int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
        {
            int ans = 0;
            int l = 0;
            int r = plants.size() - 1;
            int k1 = capacityA;
            int k2 = capacityB;
            while (l <= r)
            {
                if(l==r){
                    if(plants[l]>max(k1,k2))
                    ans++;
                    break;
                }
                if (k1 < plants[l])
                {
                    ans = ans + 1;
                    k1 = capacityA;
                }
                if (k2 < plants[r])
                {
                    ans = ans + 1;
                    k2 = capacityB;
                }

                k1 = k1 - plants[l];
                k2 = k2 - plants[r];
                l++;
                r--;
            }
            return ans;
        }
};