/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool isPrimes(int n, int *db, int size)
    {
        for (int i = 0; i < size && db[i] <= sqrt(n); ++i)
        {
            if (n % db[i] == 0)
            {
                return false;
            }
        }

        return true;
    }

    int countPrimes(int n)
    {
        int db[500000];
        int size = 0;

        if (n >= 3)
        {
            db[size++] = 2;
        }

        for (int i = 3; i < n; i += 2)
        {
            if (isPrimes(i, db, size))
            {
                db[size++] = i;
            }
        }

        return size;
    }
};
// @lc code=end
