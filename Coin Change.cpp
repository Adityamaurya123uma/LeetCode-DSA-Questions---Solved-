class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> mic(amount+1);  
        mic[0] = 0;
        for(int i =1;i<=amount;i++){
            
            long mini = INT_MAX;
               for(int j =0;j<coins.size();j++){
                  
                   long s = i - coins[j];
                   
                   if(s>=0)
                    mini = min(mini ,1+mic[s]);
                   
               }
             
             mic[i] = mini;
            
        }
        
        if(mic[amount]>=INT_MAX)return -1;
        
        
        return mic[amount];
    }
};