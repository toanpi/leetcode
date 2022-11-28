/*
 * @lc app=leetcode id=350 lang=c
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
  int min = nums1Size < nums2Size ? nums1Size : nums2Size;
  int *ret = calloc(min, sizeof(int));
  int size = 0;
  int table[1001] = {0};

  for (int i = 0; i < nums1Size; i++)
  {
    table[nums1[i]]++;
  }

  for (int i = 0; i < nums2Size; i++)
  {
    if (table[nums2[i]] > 0)
    {
      table[nums2[i]]--;
      ret[size++] = nums2[i];
    }
  }

  if (returnSize)
  {
    *returnSize = size;
  }

  return ret;
}

// @lc code=end

