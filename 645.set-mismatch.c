/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
  int *ret = malloc(2 * sizeof(int));
  int a_xor_b = 0;
  *returnSize = 2;

  for (int i = 0; i < numsSize; i++)
  {
    a_xor_b ^= nums[i];
  }

  for (int i = 1; i <= numsSize; i++)
  {
    a_xor_b ^= i;
  }

  int mr1b = a_xor_b & ~(a_xor_b - 1);
  int xor1 = 0;
  int xor0 = 0;

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] & mr1b)
    {
      xor1 ^= nums[i];
    }
    else
    {
      xor0 ^= nums[i];
    }
  }

  for (int i = 1; i <= numsSize; i++)
  {
    if (i & mr1b)
    {
      xor1 ^= i;
    }
    else
    {
      xor0 ^= i;
    }
  }

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] == xor0)
    {
      ret[0] = xor0;
      ret[1] = xor1;
      return ret;
    }
  }

  ret[0] = xor1;
  ret[1] = xor0;
  return ret;
}

// @lc code=end

