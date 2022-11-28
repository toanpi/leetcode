/*
 * @lc app=leetcode id=1018 lang=c
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize)
{
  bool *ret = malloc(numsSize * sizeof(bool));
  int size = 0;
  int remain = 0;

  for (int i = 0; i < numsSize; i++)
  {
    remain = (2 * remain + nums[i]) % 5;
    ret[size++] = !remain;
  }

  *returnSize = numsSize;
  return ret;
}

// @lc code=end

