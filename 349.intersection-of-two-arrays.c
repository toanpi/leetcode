/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size,
                  int *nums2, int nums2Size,
                  int *returnSize)
{
  bool table[1001] = {0};
  int *ret = malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
  int count = 0;

  for (int i = 0; i < nums1Size; i++)
  {
    table[nums1[i]] = true;
  }

  for (int i = 0; i < nums2Size; i++)
  {
    if (table[nums2[i]])
    {
      ret[count++] = nums2[i];
      table[nums2[i]] = false;
    }
  }

  *returnSize = count;
  return ret;
}

// @lc code=end

