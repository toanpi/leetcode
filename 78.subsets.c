/*
 * @lc app=leetcode id=78 lang=c
 *
 * [78] Subsets
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void buildSets(int* nums, int numsSize, int* returnSize, int* returnColumnSizes, int **arr)
{

}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
  int **res = calloc(1, sizeof(int *));
  int *resSize = calloc(1, sizeof(int));
  int size = 1;

  buildSets(nums, numsSize, &size, resSize, res);

  if (returnColumnSizes)
  {
    *returnColumnSizes = resSize;
  }

  if (returnSize)
  {
    *returnSize = size;
  }

  return res;
}

// @lc code=end

