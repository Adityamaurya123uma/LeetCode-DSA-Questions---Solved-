class Solution
{
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long> dp(n);
        dp[0] = 1;
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            int target = arr[i];
            int p = 0, q = i - 1;
            long ways = 1;
            while (p <= q)
            {
                long mul = (((long)arr[p]) * (arr[q]));
                if (mul == target)
                {
                    if (p == q)
                        ways += (dp[p] * dp[q]) % mod;
                    else
                        ways += ((dp[p] * dp[q]) * 2) % mod;
                    p++;
                    q--;
                }
                else if (mul < target)
                    p++;
                else if (mul > target)
                    q--;
            }
            dp[i] = ways;
            res = (int)((res + dp[i]) % mod);
        }
        return res + 1;
    }
};