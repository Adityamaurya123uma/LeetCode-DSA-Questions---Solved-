class MyCalendar
{
public:
    map<int, int> mp;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = mp.upper_bound(start);
        // it->first = min end time greater than start
        // it->second = start time of above obtained end time
        if (it == mp.end() || it->second >= end)
        {
            mp[end] = start;
            return true;
        }
        else
            return false;
    }
};