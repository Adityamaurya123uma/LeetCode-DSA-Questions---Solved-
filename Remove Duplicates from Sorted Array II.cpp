class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int i=0;
        for(auto e:nums){
            if(i==0 || i==1 || nums[i-2]!=e){
                nums[i] = e;
                i++;
            }
        }
        
        return i;
        
    }
};