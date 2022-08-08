class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> tail;

        for (int num : nums)
        {
            if (tail.empty() || num > tail.back())
            {
                tail.push_back(num);
            }
            else
            {
                tail[firstGreatEqual(tail, num)] = num;
            }
        }

        return tail.size();
    }

private:
    int firstGreatEqual(vector<int> &t, int tr)
    {
        // For finding the index of target element.
        // Lower_Bound solves via Binary Search.
        return lower_bound(t.begin(), t.end(), tr) - t.begin();
    }
};