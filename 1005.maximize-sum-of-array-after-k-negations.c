/*
 * @lc app=leetcode id=1005 lang=c
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start

int cmp(void *a, void *b)
{
  return abs(*(int *)a) - abs(*(int *)b);
}

int largestSumAfterKNegations(int *nums, int numsSize, int k)
{
  qsort(nums, numsSize, sizeof(int), cmp);

  int sum = 0;

  for (int i = numsSize - 1; (i >= 0) && (k > 0); i--)
  {
    if (nums[i] < 0)
    {
      nums[i] = -nums[i];
      k--;
    }

    if (i == 0 && k % 2)
    {
      nums[i] = -nums[i];
    }
  }

  for (int i = 0; i < numsSize; i++)
  {
    sum += nums[i];
  }

  return sum;
}

// @lc code=end

