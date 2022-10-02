class Solution
{
public:
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

#define MOD 1000000007

    int dp[31][1001];

    int numRollsToTarget(int n, int k, int target)
    {

        if (dp[n][target] != -1)
            return dp[n][target];
        int upperBound = min(k, target - n + 1), lowerBound = max(1, target - k * (n - 1)), res = 0;
        if (upperBound == lowerBound)
            return 1;
        for (int i = lowerBound; i <= upperBound; ++i)
            res = (res + numRollsToTarget(n - 1, k, target - i)) % MOD;
        dp[n][target] = res;
        return res;
    }
};