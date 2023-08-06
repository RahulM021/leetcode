class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount==100) return 0;
        int d2=purchaseAmount%10;
        int d1=(purchaseAmount/10)%10;
        if(d2>=5){
        d1++;
        return 100-d1*10;
        }
        else{
            return 100-d1*10;
        }
        return 100;
    }
};