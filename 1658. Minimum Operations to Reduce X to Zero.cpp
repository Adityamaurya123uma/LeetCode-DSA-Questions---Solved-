class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

		if(sum < x) return -1;
		if(sum == x) return nums.size();

		int target = sum - x, currentSum = 0, start = 0, maxSize = 0;
		for(int i = 0; i < nums.size(); i++) {
			currentSum += nums[i];

			while(currentSum > target)
				currentSum -= nums[start++];

			if(currentSum == target)
				maxSize = max(maxSize, i - start + 1);
		}

		return (maxSize == 0) ? - 1 : nums.size() - maxSize;

    }
};
