/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start
int removeElement(int *nums, int numsSize, int val)
{
  int count = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] != val)
    {
      nums[count++] = nums[i];
    }
  }

  return count;
}

// @lc code=end

