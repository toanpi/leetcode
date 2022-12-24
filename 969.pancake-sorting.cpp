/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ret;

        for (int i = n - 1; i >= 0;)
        {
            if (arr[i] == n)
            {
                if (i < n - 1)
                {
                    reverse(arr.begin(), arr.begin() + i + 1);
                    reverse(arr.begin(), arr.begin() + n);

                    ret.push_back(i + 1);
                    ret.push_back(n);
                }
                i = --n - 1;
            }
            else
            {
                --i;
            }
        }

        return ret;
    }
};
// @lc code=end
