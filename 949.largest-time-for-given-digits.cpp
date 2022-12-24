/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */
#include "cpp_h.h"
// @lc code=start
class Solution
{
public:

    string buildMinute(vector<int> &d)
    {
        for (char i = 5; i >= 0; --i)
        {
            if (d[i])
            {
                --d[i];

                for (char j = 9; j >= 0; --j)
                {
                    if (d[j])
                    {
                        return string({char(i + '0'), char(j + '0')});
                    }
                }

                ++d[i];
            }
        }

        return "";
    }

    string largestTimeFromDigits(vector<int> &arr)
    {
        vector<int> d(10, 0);

        for (int i = 0; i < arr.size(); ++i)
        {
            d[arr[i]]++;
        }

        for (int i = 23; i >= 0; --i)
        {
            int h0 = i / 10;
            int h1 = i % 10;
             
            if ((h0 != h1 && d[h0] && d[h1]) || (h0 == h1 && d[h0] >= 2))
            {
                --d[h0];
                --d[h1];

                string m = buildMinute(d);

                if (m.size())
                {
                    return string({char(h0 + '0'), char(h1 + '0'), ':'}) + m;
                }

                ++d[h0];
                ++d[h1];
            }
        }

        return "";
    }
};
// @lc code=end
