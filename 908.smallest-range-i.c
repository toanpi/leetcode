/*
 * @lc app=leetcode id=908 lang=c
 *
 * [908] Smallest Range I
 */

// @lc code=start

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int smallestRangeI(int *nums, int numsSize, int k)
{
  int min = 10001;
  int max = -1;
  int score = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] < min)
    {
      min = nums[i];
    }

    if (nums[i] > max)
    {
      max = nums[i];
    }
  }

  if ((max - k) > (min + k))
  {
    score = (max - k) - (min + k);
  }

  return score;
}

// @lc code=end

