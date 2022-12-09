/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    long db[51][51][51];
    long mod = 1e9 + 7;

    int _findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove <= 0)
        {
            return 0;
        }

        int i = startRow;
        int j = startColumn;
        long sum = db[i][j][maxMove];

        if(sum < 0)
        {
            long l = (j + 1 == n) ? 1 : _findPaths(m, n, maxMove - 1, i, j + 1);
            long r = (j == 0) ? 1 : _findPaths(m, n, maxMove - 1, i, j - 1);
            long u = (i + 1 == m) ? 1 : _findPaths(m, n, maxMove - 1, i + 1, j);
            long d = (i == 0) ? 1 : _findPaths(m, n, maxMove - 1, i - 1, j);

            sum = l % mod + r % mod + u % mod + d % mod;
            sum = sum % mod;

            db[i][j][maxMove] = sum;
        }

        return sum;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(db, 0xFF, sizeof(db));
        return _findPaths(m, n, maxMove, startRow, startColumn);
    }

};
// @lc code=end
