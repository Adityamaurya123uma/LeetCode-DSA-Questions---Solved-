class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
            vector<int> ans;
            int low = 0;
            int high = numbers.size()-1;
            while(low<high){
                if(numbers[low]+numbers[high] == target){
                    ans.push_back(low+1);
                    ans.push_back(high+1);
                    break;
                }
                else if(numbers[low]+numbers[high]>target) 
                    high--;
                else
                    low++;
            }
        
        
        return ans;
    }
};