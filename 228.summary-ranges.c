/*
 * @lc app=leetcode id=228 lang=c
 *
 * [228] Summary Ranges
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
  char **ret = calloc(numsSize, sizeof(char *));
  int count = 0;
  int start = numsSize > 0 ? nums[0] : 0;
  int end = start;
  bool found = false;

  for (int i = 1; i <= numsSize; i++)
  {
    if ((i < numsSize) && (nums[i] == nums[i - 1] + 1))
    {
      end = nums[i];
    }
    else
    {
      ret[count] = calloc(30, sizeof(char));

      if (start != end)
      {
        sprintf(ret[count], "%d->%d", start, end);
      }
      else
      {
        sprintf(ret[count], "%d", start);
      }

      start = end = (i < numsSize) ? nums[i] : 0;
      found = false;
      count++;
    }
  }

  *returnSize = count;
  return ret;
}

// @lc code=end

