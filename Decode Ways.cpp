class Solution
{
private:
    unordered_map<string, int> m;

public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        if (m.find(s) != m.end())
            return m[s];

        int d1 = s[0] - '0';
        if (s.length() == 1)
            return (d1 > 0 && d1 <= 26) ? 1 : 0;

        int c1 = 0, c2 = 0;
        if (d1 > 0 && d1 <= 26)
            c1 = numDecodings(s.substr(1));

        if (s.length() < 2)
            return c1;
        int d2 = stoi(s.substr(0, 2));

        if (s.length() == 2)
            return c1 + ((d2 > 0 && d2 <= 26) ? 1 : 0);
        if (d2 > 0 && d2 <= 26)
            c2 = numDecodings(s.substr(2));

        m[s] = c1 + c2;
        return m[s];
    }
};