class Solution
{
public:
    int dp[1001][102][2];
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return fun(prices, k, 0, 0); // k, index, flag( buy(0) or sell(1))
    }
    int fun(vector<int> &p, int k, int i, int f)
    {
        if (k == 0 || i >= p.size())
            return 0;

        if (dp[i][k][f] != -1)
            return dp[i][k][f];

        int t;
        if (f) // max(sell, don't sell)
            t = max(p[i] + fun(p, k - 1, i + 1, 0), fun(p, k, i + 1, 1));
        else // max(don't buy, buy) ( -1*p[i] because the buy amount need to be substracted )
            t = max(fun(p, k, i + 1, 0), -1 * p[i] + fun(p, k, i + 1, 1));
        dp[i][k][f] = t;
        return t;
    }
};