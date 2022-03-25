//Best Approach 
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int l=0;
        int m=0;
        int h=nums.size()-1;
        while(m<=h){
            if(nums[m]==1){
                m++;
            }
            else if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==2){
                swap(nums[h],nums[m]);
                h--;
            }
        }
    }
};

// Second Approach

// Time Complexity : O(n)
// Space Complexity : O(n)
/* class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>temp;
        int count0=0;
        int count1=0;
        int count2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }
            if(nums[i]==1){
                count1++;
            }
            if(nums[i]==2){
                count2++;
            }
        }
        
       
            while(count0>0){
                temp.push_back(0);
                count0--;
            }
            while(count1>0){
                temp.push_back(1);
                count1--;
            }
            while(count2>0){
                temp.push_back(2);
                count2--;
            }
       
        
        for(int i=0;i<nums.size();i++){
            nums[i]=temp[i];
        }
    }
}; */