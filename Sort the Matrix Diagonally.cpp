class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size(), p = mat[0].size();
        map<int, priority_queue<int, vector<int>, greater<int>>> diag;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                diag[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                mat[i][j] = diag[i - j].top();
                diag[i - j].pop();
            }
        }
        return mat;
    }
};