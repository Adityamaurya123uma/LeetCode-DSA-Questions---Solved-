class Solution
{
public:
    int solve(string &s, string &stamp)
    {

        for (int i = 0; i < s.size(); i++)
        {
            int idx1 = i;
            int idx2 = 0;
            bool f = false;

            while (idx1 < s.size() && idx2 < stamp.size() && (s[idx1] == '*' || s[idx1] == stamp[idx2]))
            {
                if (s[idx1] == stamp[idx2])
                    f = true;
                idx1++;
                idx2++;
            }

            if (f && idx2 == stamp.size())
            {
                for (int j = 0; j < stamp.size(); j++)
                {
                    s[i + j] = '*';
                }
                return i;
            }
        }

        return -1;
    }

    vector<int> movesToStamp(string stamp, string target)
    {

        vector<int> ans;
        string aim(target.size(), '*');
        string s = target;

        while (s != aim)
        {
            int idx = solve(s, stamp);
            if (idx == -1)
                return {};
            ans.push_back(idx);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};