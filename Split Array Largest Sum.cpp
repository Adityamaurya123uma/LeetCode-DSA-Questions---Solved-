class Solution {
public:
     const int MOD=1e9+7;
    int dp[1002][52];
    
    int f(int i,int m,vector<int>& nums){
        if(i==nums.size()){
            return (m)? MOD:0;
        }
        if(!m)return MOD;
        if(m==1){
            int sum=accumulate(nums.begin()+i,nums.end(),0LL);
            return sum;
        }
        if(dp[i][m]!=-1)return dp[i][m];
        int ans=MOD;
        
        int sum=0;
        for(int j=i;j<nums.size()-m+1;j++){
            sum+=nums[j];
            ans=min(ans,max(sum,f(j+1,m-1,nums)));
        }
        return dp[i][m]=ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
         memset(dp,-1,sizeof(dp));
        return f(0,m,nums);
    }
};