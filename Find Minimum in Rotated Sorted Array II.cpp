class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum;
        for(int i=0;i<nums.size();i++){
            minimum = min(minimum,nums[i]);
        }
        return minimum;
    }
};