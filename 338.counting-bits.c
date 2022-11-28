/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *countBits(int n, int *returnSize)
{
  int *ret = malloc((n + 1) * sizeof(int));
  int start = 0;

  ret[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    ret[i] = i % 2 ? ret[start++] + 1 : ret[start];
  }

  if (returnSize)
  {
    *returnSize = n + 1;
  }

  return ret;
}

// @lc code=end

