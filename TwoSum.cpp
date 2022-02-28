//Two Sum C++ Easy
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        unordered_map<int , int> map;
        int n = nums.size();
         for(int i=0;i<n;i++){
             if(map.find(target - nums[i])!=map.end()){
                 ans.push_back(map[target-nums[i]]);
                 ans.push_back(i);
                 return ans;
             }
             map[nums[i]]=i;
         }
     
        
    return ans; 
    }
};