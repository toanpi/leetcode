/*
 * @lc app=leetcode id=728 lang=c
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isSelfDividing(int a)
{
  int n = a;

  while (n)
  {
    if ((n % 10) == 0 || a % (n % 10))
    {
      return false;
    }
    n /= 10;
  }

  return true;
}

int *selfDividingNumbers(int left, int right, int *returnSize)
{
  int *ret = malloc((right - left + 1) * sizeof(int));
  int size = 0;

  for (int i = left; i <= right; i++)
  {
    if (isSelfDividing(i))
    {
      ret[size++] = i;
    }
  }

  *returnSize = size;
  return ret;
}

// @lc code=end
