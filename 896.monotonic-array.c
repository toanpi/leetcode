/*
 * @lc app=leetcode id=896 lang=c
 *
 * [896] Monotonic Array
 */

// @lc code=start

bool isMonotonic(int *nums, int numsSize)
{
  bool inc = false;
  bool des = false;

  for (int i = 0; i < numsSize - 1; i++)
  {
    if(nums[i] < nums[i+1]) inc = true;
    if(nums[i] > nums[i+1]) des = true;

    if(inc && des) return false;
  }

  return true;
}

// @lc code=end

