/*
 * @lc app=leetcode id=674 lang=c
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start

int findLengthOfLCIS(int *nums, int numsSize)
{
  int max = 1;
  int cnt = 1;

  for (int i = 0; i < numsSize - 1; i++)
  {
    cnt = (nums[i] < nums[i + 1]) ? cnt + 1 : 1;

    if (cnt > max)
    {
      max = cnt;
    }
  }

  return max;
}

// @lc code=end
