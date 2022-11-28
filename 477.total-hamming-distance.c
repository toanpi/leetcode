/*
 * @lc app=leetcode id=477 lang=c
 *
 * [477] Total Hamming Distance
 */

// @lc code=start

int hammingDistance(int a, int b)
{
  return __builtin_popcount(a ^ b);
}

#define min(a, b) ((a) < (b) ? (a) : (b))

int totalHammingDistance(int *nums, int numsSize)
{
  int cnt = 0;

  for (int i = 0; i < numsSize - 1; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      cnt += hammingDistance(nums[i], nums[j]);
    }
  }

  return cnt;
}

// @lc code=end

