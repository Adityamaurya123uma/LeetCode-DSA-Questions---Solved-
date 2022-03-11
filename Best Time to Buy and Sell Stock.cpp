class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprices = 0;
        int minprices = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            minprices = min(minprices,prices[i]);
            maxprices = max(maxprices,prices[i] - minprices);
        }
        
        return maxprices;;
    }
};