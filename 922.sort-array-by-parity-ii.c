/*
 * @lc app=leetcode id=922 lang=c
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int *sortArrayByParityII(int *nums, int numsSize, int *returnSize)
{
  for (int i = 0, j = 1; i < numsSize; i += 2)
  {
    if ((nums[i] % 2))
    {
      while (nums[j] % 2) j += 2;
      swap(&nums[i], &nums[j]);
    }
  }

  if (returnSize) *returnSize = numsSize;
  return nums;
}

// @lc code=end

