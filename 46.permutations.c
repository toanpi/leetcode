/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int calPermute(int n)
{
  int sum = 1;
  while (n > 1)
  {
    sum *= n;
    n--;
  }
  return sum;
}

int **permute(int *nums, int numsSize,
              int *returnSize, int **returnColumnSizes)
{
  if (numsSize == 0) return NULL;

  int numPer = calPermute(numsSize);
  int **ret = malloc(numPer * sizeof(int *));
  int *size = malloc(numPer * sizeof(int));
  int len = 0;

  for (int i = 0; i < numsSize; i++)
  {
    int listSize = 1;
    int *colSize = NULL;
    int **list = NULL;

    // Get permute list
    if (numsSize > 1)
    {
      swap(&nums[0], &nums[i]);
      list = permute(&nums[1], numsSize - 1, &listSize, &colSize);
      swap(&nums[i], &nums[0]); // backtrack
    }

    // Build permute start with nums[i]
    for (int j = 0; j < listSize; j++)
    {
      ret[len] = malloc(numsSize * sizeof(int));
      ret[len][0] = nums[i];
      size[len] = numsSize;

      if (list)
      {
        memcpy(&ret[len][1], list[j], colSize[j] * sizeof(int));
        free(list[j]);
      }

      len++;
    }

    if (colSize) free(colSize);
  }

  *returnColumnSizes = size;
  *returnSize = numPer;
  return ret;
}

// @lc code=end

