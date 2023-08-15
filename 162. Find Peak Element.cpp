class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;
        
        while(low<=high){

            int mid = (low+high)/2;
            if(nums[mid-1] < nums[mid] && nums[mid]>nums[mid+1]) {
                return mid; // on the peak.
            }

            if( nums[mid] > nums[mid-1]) {
                low = mid+1; // mid is on the increasing curve so delete the left half.
            }else if ( nums[mid] > nums[mid+1]) {
                high = mid-1; // mid is on the decreasing curve so delete the right half.
            } else {
                low = mid +1; // exactly between two peak.
            }
        }
        return -1;
    }
};
