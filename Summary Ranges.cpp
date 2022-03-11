class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        if(nums.size() == 0){
            return ans;
        }
        
        int start = nums[0];
        int end = nums[0];
       
        
        for(int i=1;i<nums.size();i++){
            if(end+1 == nums[i]){
                end = nums[i];
            }
            else{
                if(start == end){
                    string temp = to_string(start);
                    ans.push_back(temp);
                }
                else{
                    string temp = to_string(start);
                    temp+="->";
                    temp+=to_string(end);
                    ans.push_back(temp);
                }
                    start = nums[i];
                    end = nums[i];
            }
        }
        
        if(start == end){
            string temp = to_string(start);
            ans.push_back(temp);
        }
        else{
            string temp = to_string(start);
            temp+="->";
            temp+=to_string(end);
            ans.push_back(temp);
        }
        
        
        
        return ans;
    }
};