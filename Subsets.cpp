class Solution {
public:
    
    vector<vector<int>> allsubsets;
        void generate(vector<int> subsets , int i,vector<int> nums){
            if(i==nums.size()){
                allsubsets.push_back(subsets);
                return;
            }
            
            generate(subsets,i+1,nums);
            subsets.push_back(nums[i]);
            generate(subsets,i+1,nums);
            subsets.pop_back();
        }
        
        vector<vector<int>> subsets(vector<int> nums){
            
            vector<int> empty;
            generate(empty,0,nums);
            return allsubsets;
        }
};