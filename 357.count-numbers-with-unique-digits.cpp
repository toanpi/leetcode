/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    vector<int> fact = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 326880};

    int countNumbersWithUniqueDigits(int n)
    {
        if (n <= 1)
        {
            return n == 1 ? 10 : 1;
        }

        return (3265920 / fact[9 - n + 1]) + countNumbersWithUniqueDigits(n - 1);
    }
};
// @lc code=end
