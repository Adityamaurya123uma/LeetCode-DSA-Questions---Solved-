class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size()==1){
            return;
        }
        
        int index1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        
        if(index1<0){
            sort(nums.begin(),nums.end());
        }else{
            
            int index2=0;
            for(int i=nums.size() -1;i>=0;i--){
                if(nums[i]>nums[index1]){
                    index2=i;
                    break;
                }
            }
            
            swap(nums[index1],nums[index2]);
            reverse(nums.begin()+index1+1,nums.end());
        }
        
    }
};