/*
 * @lc app=leetcode id=989 lang=c
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addToArrayForm(int *num, int numSize, int k, int *returnSize)
{
  int len = numSize > 5 ? numSize + 1 : 6;
  int *ret = calloc(len, sizeof(int));
  int n = 0;
  int i = numSize - 1;
  int idx = len - 1;

  while (k || (i >= 0) || n)
  {
    n += (k % 10) + ((i >= 0) ? num[i] : 0);

    ret[idx--] = n % 10;

    k /= 10;
    n /= 10;
    i--;
  }

  *returnSize = len - 1 - idx;

  return &ret[idx + 1];
}

// @lc code=end

