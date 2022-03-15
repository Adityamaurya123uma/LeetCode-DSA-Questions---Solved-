class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]%2 == 1 && nums[j]%2 == 0)
                
            {
                swap(nums[i],nums[j]);
                i+=1;
                j-=1;
                continue;
            }
            if(nums[i]%2 == 0 && nums[j]%2 == 1){
                i+=1;
                j-=1;
                continue;
            }
            if(nums[i]%2 == 0 && nums[j]%2 == 0){
                i+=1;
                continue;
                
            }
       if(nums[i]%2 == 1 && nums[j]%2 == 1){
           j-=1;
           continue;
        }
        }
        
        return nums;
    }
};

// Not optimal - Using extra sapce

//  int n=nums.size();
//         vector<int> ans;
        
//         for(int i=0;i<n;i++){
//             if(nums[i]%2==0){
//                 ans.push_back(nums[i]);
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(nums[i]%2!=0){
//                 ans.push_back(nums[i]);
//             }
//         }
        
//         return ans;