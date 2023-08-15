// Brute force approach
// Time complexity : O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum;
        for(int i=0;i<nums.size();i++){
            minimum = min(minimum,nums[i]);
        }
        return minimum;
    }
};

// Optimized approach [Bineary Search]
// Time complexity : O(logn)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = (low+high) / 2;
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            if(nums[mid] <= nums[high]){
                ans = min(ans,nums[mid]);
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
