/*
 * @lc app=leetcode id=485 lang=c
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
  int max = 0;
  int cnt = 0;

  for (int i = 0; i < numsSize; i++)
  {
    cnt += nums[i];

    if (cnt > max)
    {
      max = cnt;
    }

    if(!nums[i]) cnt = 0;
  }

  return max;
}

// @lc code=end

