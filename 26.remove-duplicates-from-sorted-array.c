/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int *nums, int numsSize)
{
  int count = 1;
  int cur = nums[0];

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] != cur)
    {
      cur = nums[i];
      nums[count++] = cur;
    }
  }

  return count;
}

// @lc code=end

