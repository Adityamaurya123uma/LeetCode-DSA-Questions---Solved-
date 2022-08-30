class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
};

// method 2

class Solution
{
public:
    void roro(vector<vector<int>> &matrix, int i, int k, int n)
    {
        for (int j = 0; j < k; j++)
        {
            int t = matrix[i][i + j];
            matrix[i][i + j] = matrix[n - i - 1 - j][i];
            matrix[n - i - 1 - j][i] = matrix[n - i - 1][n - i - 1 - j];
            matrix[n - i - 1][n - i - 1 - j] = matrix[i + j][n - i - 1];
            matrix[i + j][n - i - 1] = t;
        }
    }

    void rotate(vector<vector<int>> &matrix)
    {
        int i = 0, n = matrix.size();
        int k = n - 1;
        while (k > 0)
        {
            roro(matrix, i, k, n);
            i++;
            k -= 2;
        }
        return;
    }
};