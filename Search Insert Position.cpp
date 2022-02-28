class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pos=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                pos = i;
                break;
            }
            if(nums[i]>target){
                pos = i;
                break ; 
            }if(nums[i]>target){
                pos = i;
                break ; 
            }if(target>nums[n-1]){
                pos = n;
                break ; 
            }
        }
        
        
        return pos;
    }
};