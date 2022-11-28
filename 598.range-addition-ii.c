/*
 * @lc app=leetcode id=598 lang=c
 *
 * [598] Range Addition II
 */

// @lc code=start

#define min(a, b) ((a) < (b) ? (a) : (b))

int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize)
{
  for (int i = 0; i < opsSize; i++)
  {
    if(ops[i][0] < m) m = ops[i][0];
    if(ops[i][1] < n) n = ops[i][1];
  }

  return n * m;
}

// @lc code=end

