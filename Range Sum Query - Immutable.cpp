class NumArray {
public: 
    
    vector<int>nums;
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
        prefix.resize(n);
        prefixcalculate(nums);
    }
    
    int sumRange(int left, int right) {
        if(left-1>=0){
            return prefix[right]-prefix[left-1];
        }else{
            return prefix[right];
        }
    }
    
    void prefixcalculate(vector<int>nums){
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefix[i]=nums[i];
            }else{
                prefix[i]=nums[i]+prefix[i-1];
            }
        }
    }
};