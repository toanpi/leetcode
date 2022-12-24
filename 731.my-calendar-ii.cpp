/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */
#include "cpp_h.h"

// @lc code=start
class MyCalendarTwo
{
public:
    multimap<int, int> q;
    map<int, int> inter;

    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (auto r : inter)
        {
            if (!(r.first >= end || r.second <= start))
            {
                return false;
            }

            if (r.first >= end)
                break;
        }

        for (auto r : q)
        {
            if (!(r.first >= end || r.second <= start))
            {
                inter.insert({max(start, r.first), min(end, r.second)});
            }

            if (r.first >= end)
                break;
        }

        q.insert({start, end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
