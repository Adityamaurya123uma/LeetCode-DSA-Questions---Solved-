class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm(nums, 0);
        return res;
    }

    void perm(vector<int>& nums, int start) {
        if(start==nums.size()) {
            if (count(res.begin(), res.end(), nums)==0) {
                 res.push_back(nums);
        }
            
            return;
        }
            
        for(int i=start; i<nums.size(); i++) {
            swap(nums[i], nums[start]);
            perm(nums, start+1);
            swap(nums[i], nums[start]);
        }
    return;
    }
};