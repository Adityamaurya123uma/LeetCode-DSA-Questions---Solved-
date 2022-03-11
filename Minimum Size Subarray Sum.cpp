class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left =0,result=INT_MAX;
        
        for(int i=0;i<n;i++){
            sum = sum+nums[i];
            while(sum>=target){
                result = min(result,i+1-left);
                sum = sum - nums[left];
                left++;
            }
        }
        
        if(result==INT_MAX){
            return 0;
        }
        else{
        return result;
        }
    }
};