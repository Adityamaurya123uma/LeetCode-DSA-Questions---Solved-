Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7

Example 2:
Input: nums = [9], target = 3
Output: 0

class Solution
{
public:
    vector<int> dp;

    Solution()
    {
        dp.resize(1001);
        fill(dp.begin(), dp.end(), -1);
    }

    int combinationSum4(vector<int> &nums, int target, int currSum = 0)
    {
        if (currSum > target)
            return 0;
        if (currSum == target)
            return 1;
        if (dp[currSum] != -1)
            return dp[currSum];
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (currSum + nums[i] <= target)
                ways += combinationSum4(nums, target, currSum + nums[i]);
        }
        return dp[currSum] = ways;
    }
};
