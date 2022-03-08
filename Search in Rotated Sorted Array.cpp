class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[high] > nums[mid]) {  // right half
                if(nums[mid] < target && nums[high] >= target) { // sorted
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else { // nums[l] < nums[mid] left half
                if(nums[low] <= target && nums[mid] > target) { // sorted
                    high = mid -1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};