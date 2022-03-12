class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix_product(n);
        vector<int> suffix_product(n);
        
        for(int i = 0 ;i<nums.size();i++){
            if(i==0){
               prefix_product[i] = 1;
            }
            else {
               prefix_product[i] = nums[i-1] * prefix_product[i-1];
            }
        } 
        
        for(int i = nums.size()-1 ; i>=0 ;i--){
            if(i==nums.size()-1){
                suffix_product[i] = 1;
            }
            else{
                suffix_product[i] = nums[i+1] * suffix_product[i+1];
            }
        }  
        
        for(int i = 0 ; i<nums.size();i++){
            suffix_product[i] = suffix_product[i] * prefix_product[i];
        }
        
        return suffix_product;
        
    }
};