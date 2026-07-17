class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniPrice=prices[0];
        int maxi=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int cost=prices[i]-miniPrice;
            maxi=max(maxi,cost);
            miniPrice=min(miniPrice,prices[i]);
        }
        return maxi;
    }
};