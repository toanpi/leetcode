/*
 * @lc app=leetcode id=697 lang=c
 *
 * [697] Degree of an Array
 */

// @lc code=start

#define SIZE    50000

int findShortestSubArray(int *nums, int numsSize)
{
  struct
  {
    int len;
    int start;
    int cnt;
  } count[SIZE] = {0};

  int degree = 0;
  int min = numsSize;

  for (int i = 0; i < numsSize; i++)
  {
    int cnt = ++count[nums[i]].cnt;

    if (cnt == 1)
    {
      count[nums[i]].start = i;
    }

    count[nums[i]].len = i - count[nums[i]].start + 1;

    if (cnt > degree)
    {
      degree = cnt;
      min = count[nums[i]].len;
    }
    else if (cnt == degree)
    {
      if (count[nums[i]].len < min)
      {
        min = count[nums[i]].len;
      }
    }
  }

  return min;
}
// @lc code=end
