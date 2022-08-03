class MyCalendar
{
private:
    vector<pair<int, int>> m;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto it : m)
        {
            if (it.first < end and it.second > start)
                return false;
        }
        m.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar
{
private:
    map<int, int> mp;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for (auto it : mp)
        {
            sum += it.second;
            if (sum > 1)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */