class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int n=nums.size();
   
  
     
    sort(nums.begin(),nums.end());
     int x=nums[n-1];
  
    int i;
    for( i=0;i<=x;i++){
        if(i!=nums[i] ){ return i;}
        
    }
    return i;
    }
};