class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        else
            return (n % 2 == 0 && isPowerOfTwo(n / 2));
    }
};

// Second Approach
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;

        while (1)
        {
            if (n == 1 || n == 4)
                return true;
            if (n % 4 != 0)
                return false;
            n = n / 4;
        };
        return true;
    }
};