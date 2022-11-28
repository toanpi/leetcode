/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
  int even = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] % 2)
    {
      even = even > i ? even : i;

      while ((even < numsSize) && (nums[even] % 2))
      {
        even++;
      }

      if (even >= numsSize)
      {
        break;
      }

      int temp = nums[i];
      nums[i] = nums[even];
      nums[even] = temp;
    }
  }

  if (returnSize)
  {
    *returnSize = numsSize;
  }
  return nums;
}

// @lc code=end

