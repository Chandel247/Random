class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought=prices[0];
        int profit=0;
        for (int i=0;i<prices.size();i++){
            if (prices[i]<bought){
                bought=prices[i];
            }
            else if (prices[i]>bought && (prices[i]-bought)>profit){
                profit=prices[i]-bought;
            }
        }
        return profit;
    }
};