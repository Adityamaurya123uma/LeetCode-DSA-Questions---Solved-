class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate = INT_MIN;
        int life = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){
                life++;
            }
            else if(life == 0 ){
                candidate = nums[i];
                life = 1;
            }
            else{
                life --;
            }
        }
        
        return candidate;
    }
};