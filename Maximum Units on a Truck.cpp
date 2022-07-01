class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int n = boxTypes.size();
        int count = 0;
        int maxunit = 0;

        for (int i = 0; i < n; i++)
        {
            if (boxTypes[i][0] + count < truckSize)
            {
                maxunit = maxunit + (boxTypes[i][0] * boxTypes[i][1]);
                count = count + boxTypes[i][0];
            }
            else
            {
                maxunit = maxunit + (truckSize - count) * boxTypes[i][1];
                break;
            }
        }
        return maxunit;
    }
};