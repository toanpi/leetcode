/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
  int **ret = malloc(numRows * sizeof(int *));
  int *size = malloc(numRows * sizeof(int));

  for (int i = 0; i < numRows; i++)
  {
    ret[i] = malloc((i + 1) * sizeof(int));
    size[i] = i + 1;

    if (i == 0)
    {
      ret[i][0] = 1;
      continue;
    }

    // Fill data
    int a = -1;
    int b = 0;

    for (int j = 0; j < i + 1; j++)
    {
      ret[i][j] = ((a >= 0) ? ret[i - 1][a] : 0) + ((b < i) ? ret[i - 1][b] : 0);
      a++;
      b++;
    }
  }

  *returnColumnSizes = size;
  *returnSize = numRows;

  return ret;
}

// @lc code=end

