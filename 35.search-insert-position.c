/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target)
{
  int res = -1;
  int lo = 0;
  int hi = numsSize - 1;
  int mid = 0;

  // 1, 3, 5, 6 -> 2
  // 0 - 3
  // 2, 3 -> 5/2 = 2

  while (lo <= hi)
  {
    mid = (hi + lo) / 2;

    if (nums[mid] == target)
    {
      res = mid;
      break;
    }
    else if (target > nums[mid])
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  if (res < 0)
  {
    res = lo;
  }

  return res;
}
// @lc code=end

