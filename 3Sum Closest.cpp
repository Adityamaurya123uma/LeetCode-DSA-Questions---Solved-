class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int distance = INT_MAX;
        int sum;
        int final_sum;
            for(int i=0;i<nums.size();i++)
            {
                int j = i+1;
                int z = nums.size()-1;
                
                while(j<z)
                { 
                    int earlier_distance = distance;
                     int sum = (nums[i] + nums[z] + nums[j]);
                     if(sum<0&&target<0)
                        distance = min(distance,abs(abs(sum)-abs(target)));
                     else if(sum>0&&target<0||(sum<0&&target>0))
                        distance = min(distance,(abs(sum)+abs(target)));
                     else
                        distance = min(distance,abs(abs(sum)-abs(target)));
                     if(distance<earlier_distance)
                        final_sum = (nums[i] + nums[z] + nums[j]);
                     if(target>=sum)
                        j++;
                     else
                        z--;
                }
            }
        return final_sum; 
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         int diff=INT_MAX;
//         int sum =0;
        
//         for(int i=0;i<n-2;i++){
//             int val=nums[i];
//             int l=nums[i+1];
//             int r=n-1;
            
//             while(l<r){
//                 sum=val+nums[l]+nums[r];
//                 if(sum==target){
//                     return target;
//                 }
//                 else if(abs((sum)-target)<diff){
//                     diff = abs((sum)-target);
//                 }
//                 if(sum>target){
//                     r--;
//                 }
//                 else{
//                     l++;
//                 }
//             }
            
//         }
        
//         return sum;
        
    }
};