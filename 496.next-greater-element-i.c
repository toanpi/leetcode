/*
 * @lc app=leetcode id=496 lang=c
 *
 * [496] Next Greater Element I
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
  int idxs[10001] = {0};
  int *ret = malloc(nums1Size * sizeof(int));
  int size = 0;

  for (int i = 0; i < nums2Size; i++)
  {
    idxs[nums2[i]] = i;
  }

  for (int i = 0; i < nums1Size; i++)
  {
    ret[size] = -1;

    for (int j = idxs[nums1[i]] + 1; j < nums2Size; j++)
    {
      if (nums2[j] > nums1[i])
      {
        ret[size] = nums2[j];
        break;
      }
    }

    size++;
  }

  if (returnSize)
  {
    *returnSize = size;
  }
  return ret;
}
// @lc code=end

