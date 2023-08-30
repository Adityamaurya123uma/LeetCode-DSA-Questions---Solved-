class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long ans =0;
        int n = nums.size();
        int prev = nums[n-1];
        for(int i=n-2;i>=0;i--){
            int temp = nums[i]/prev;
            if(nums[i]%prev!=0){
                temp++;
            }
            if((nums[i])%prev!=0){
                prev=nums[i]/temp;
            }
            ans=ans+temp-1;
        }
        return ans;
    }
};
