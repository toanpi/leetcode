/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start

void swap(int *a, int *b)
{
  int n = *a;
  *a = *b;
  *b = n;
}

void moveZeroes(int *nums, int numsSize)
{
  int start = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i]) swap(&nums[i], &nums[start++]);
  }
}

// @lc code=end

