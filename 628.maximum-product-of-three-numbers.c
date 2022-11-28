/*
 * @lc app=leetcode id=628 lang=c
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start

int maximumProduct(int *nums, int numsSize)
{
  int max3 = INT_MIN;
  int max2 = INT_MIN;
  int max1 = INT_MIN;
  int min1 = INT_MAX;
  int min2 = INT_MAX;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] >= max3)
    {
      max1 = max2;
      max2 = max3;
      max3 = nums[i];
    }
    else if (nums[i] >= max2)
    {
      max1 = max2;
      max2 = nums[i];
    }
    else if (nums[i] >= max1)
    {
      max1 = nums[i];
    }

    if (nums[i] <= min2)
    {
      min1 = min2;
      min2 = nums[i];
    }
    else if (nums[i] <= min1)
    {
      min1 = nums[i];
    }
  }

  int pro1 = max1 * max2 * max3;
  int pro2 = max3 * min1 * min2;

  return pro1 > pro2 ? pro1 : pro2;
}

// @lc code=end

