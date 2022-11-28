/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
  int *ret = malloc((rowIndex + 1) * sizeof(int));

  for (int i = 0; i <= rowIndex; i++)
  {
    ret[0] = ret[i] = 1;

    int n = ret[0] + ((i > 0) ? ret[1] : 0);
    int temp = 0;

    for (int j = 1; j < i; j++)
    {
      temp = ret[j] + ret[j + 1];
      ret[j] = n;
      n = temp;
    }
  }

  *returnSize = rowIndex + 1;
  return ret;
}

// @lc code=end

