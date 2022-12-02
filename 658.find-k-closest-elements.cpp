/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l = 0;
        int r = arr.size() - 1;
        int m = 0;
        int size = k;
        int start = -1;
        int idx = r;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            idx = arr[m] >= x ? m : idx;

            if (arr[m] == x) break;

            arr[m] < x ? l = m + 1: r = m - 1;
        }

        r = idx;
        l = idx - 1;

        while (k--)
        {
            if (l < 0 || (r < arr.size() && (abs(arr[l] - x) > abs(arr[r] - x))))
            {
                start < 0 ? start = r++ : r++;
            }
            else
            {
                start = l--;
            }
        }

        return vector<int>(arr.begin() + start, arr.begin() + start + size);
    }
};
// @lc code=end
