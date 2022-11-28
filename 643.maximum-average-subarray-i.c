/*
 * @lc app=leetcode id=643 lang=c
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start

double findMaxAverage(int *nums, int numsSize, int k)
{
  long max = LONG_MIN;
  long sum = 0;

  for (int i = 0; i < numsSize; i++)
  {
    sum += nums[i] - (i >= k ? nums[i - k] : 0);

    if (i >= (k - 1) && sum > max)
    {
      max = sum;
    }
  }

  return ((double)max) / k;
}

// @lc code=end

