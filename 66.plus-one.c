/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
  int len = digitsSize + 1;
  int *ret = calloc(len, sizeof(int));
  int n = 1;
  int i = digitsSize - 1;
  int idx = len - 1;

  while (n || i >= 0)
  {
    n += i >= 0 ? digits[i] : 0;

    ret[idx--] = n % 10;

    n /= 10;
    i--;
  }

  *returnSize = len - 1 - idx;
  return &ret[idx + 1];
}

// @lc code=end

