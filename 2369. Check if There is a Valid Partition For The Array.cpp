class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return fnc(nums, 0, dp);
    }
    bool fnc(vector<int>& nums, int i,vector<int>& dp){
        // Base Condition
        if ( i == nums.size() ) {
            return true;
        }
        // Prevents form unncessary calling the function for same indexes again and again
        if ( dp[i] != -1 ) {
            return dp[i];
        }
        //Case 1: 2 equal element
        if ( i + 1 < nums.size() && nums[i+1] == nums[i] ) {
            if ( fnc( nums, i+2, dp) ){
                return dp[i]=true;
            }

            //Case 2: 3 equal element
            if ( i + 2 < nums.size() && nums[i+2] == nums[i] ) {
                if ( fnc( nums, i+3, dp) ) {
                    return dp[i]=true;
                }
            }
        }

        //Case 3: 3 elements in increasing order
        if ( i+2 < nums.size() && nums[i+1] == nums[i] + 1 && nums[i+2] == nums[i] + 2 ) {
            if ( fnc(nums, i+3, dp) ) {
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    } 
};
