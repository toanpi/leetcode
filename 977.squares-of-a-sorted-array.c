/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
  int *ret = malloc(numsSize * sizeof(int));
  int p = numsSize - 1;
  int n = 0;
  int k = numsSize - 1;

  while (k >= 0)
  {
    ret[k--] = abs(nums[p]) > abs(nums[n]) ? nums[p] * nums[p--] : nums[n] * nums[n++];
  }

  if (returnSize)
  {
    *returnSize = numsSize;
  }

  return ret;
}

// @lc code=end

