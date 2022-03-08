class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        int sum = target;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == sum) {
                temp.push_back(i);
            }
        }
        vector<int> ans;
        if(temp.size() > 0) {
            ans.push_back(temp[0]);
            ans.push_back(temp[temp.size() - 1]);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
    }
};