class Solution
{
public:
    string breakPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
        {
            return "";
        }
        char ch = 'a';
        int idx = -1;
        int mid = s.size() / 2;
        for (int i = 0; i < s.size(); i++)
        {
            if (ch < s[i] && i != mid)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            // condition for "aaaaaaa.....aaaaa"
            if (s[n - 1] == 'a')
            {
                s[n - 1] = 'b';
            }
        }
        else
        {
            // general condition just replace the character by 'a' at index idx to make it lexographically smallest
            s[idx] = 'a';
        }
        return s;
    }
};