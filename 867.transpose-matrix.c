/*
 * @lc app=leetcode id=867 lang=c
 *
 * [867] Transpose Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **transpose(int **matrix, int matrixSize,
                int *matrixColSize, int *returnSize,
                int **returnColumnSizes)
{
  int **ret = malloc(matrixColSize[0] * sizeof(int *));
  int *size = malloc(matrixColSize[0] * sizeof(int));

  for (int i = 0; i < matrixColSize[0]; i++)
  {
    ret[i] = malloc(matrixSize * sizeof(int));
    size[i] = matrixSize;
  }

  for (int i = 0; i < matrixSize; i++)
  {
    for (int j = 0; j < matrixColSize[i]; j++)
    {
      ret[j][i] = matrix[i][j];
    }
  }

  *returnSize = matrixColSize[0];
  *returnColumnSizes = size;
  return ret;
}

// @lc code=end

