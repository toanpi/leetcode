/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start


int majorityElement(int* nums, int numsSize)
{
  int candidate = 0;
  int vote = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (vote == 0)
    {
      candidate = nums[i];
    }

    vote += nums[i] != candidate ? -1 : 1;
  }

  return candidate;
}
// @lc code=end

