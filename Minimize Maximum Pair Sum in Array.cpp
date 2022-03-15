class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>sum;
        int l=0;
        int h=n-1;
        while(l<h){
            int temp=0;
            temp=nums[l]+nums[h];
            sum.push_back(temp);
            l++;
            h--;
        }
        int ans=0;
        for(int i=0;i<sum.size();i++){
            ans=max(ans,sum[i]);
        }
        
        return ans;
    }
};