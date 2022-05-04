class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int l=0,r=n-1;
        
        while(l<r){
            if(nums[l]+nums[r] == k){
                count++;
                l++;
                r--;
            }       
            if(nums[l]+nums[r]<k){
                l++;
            }
            if(nums[l]+nums[r]>k){
                r--;
            }
        }
     return count;   
    }
};