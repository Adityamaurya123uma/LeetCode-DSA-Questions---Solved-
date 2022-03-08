class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                continue;
            }
                int low = j+1;
                int high = n-1;
                int sum = target - (nums[i]+nums[j]);
                while(low<high){
                    
                    
                    if(nums[low]+nums[high] == sum){
                        vector<int> temp = {nums[i],nums[j],nums[low],nums[high]};
                        ans.push_back(temp);
                        while(low<high && nums[low] == nums[low+1]){
                            low++;
                        }
                        while(low>high && nums[high] == nums[high-1]){
                            high--;
                        }
                        low++;
                        high--;
                    }
                    else if(nums[low]+nums[high]<sum){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};