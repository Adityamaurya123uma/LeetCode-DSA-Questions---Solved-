// MOST BASIC APPROACH
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        int sum = target;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == sum) {
                temp.push_back(i);
            }
        }
        vector<int> ans;
        if(temp.size() > 0) {
            ans.push_back(temp[0]);
            ans.push_back(temp[temp.size() - 1]);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
    }
};

// BINEARY SEARCH APPROACH

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0;
        high = n-1;
        int last = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
