/*
 * @lc app=leetcode id=448 lang=c
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
  int len = 0;

  for (int i = 0; i < numsSize; i++)
  {
    nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
  }

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] > 0)
    {
      nums[len++] = i + 1;
    }
  }

  *returnSize = len;
  return nums;
}

// @lc code=end

