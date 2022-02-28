class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     
        vector<int> :: iterator it;
        it = nums.begin();
        
        for(int j=0;j<nums.size();j++){
            if(nums[j] == val){
                nums.erase(it);
                it--;
                j--;
            }
            it++;
        }
        
        return nums.size();
    }
};