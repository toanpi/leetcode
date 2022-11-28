/*
 * @lc app=leetcode id=976 lang=c
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start

int cmp(void *a, void *b)
{
  return *(int *)a - *(int *)b;
}

int largestPerimeter(int *nums, int numsSize)
{
  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = numsSize - 1; i >= 2; i--)
  {
    if (nums[i - 1] + nums[i - 2] > nums[i])
    {
      return nums[i] + nums[i - 1] + nums[i - 2];
    }
  }

  return 0;
}

// @lc code=end

