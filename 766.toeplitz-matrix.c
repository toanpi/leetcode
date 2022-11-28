/*
 * @lc app=leetcode id=766 lang=c
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start

bool isToeplitzMatrix(int **matrix, int matrixSize, int *matrixColSize)
{
  for (int i = 0; i < matrixSize - 1; i++)
  {
    for (int j = 0; j < matrixColSize[i] - 1; j++)
    {
      if (matrix[i][j] != matrix[i + 1][j + 1])
      {
        return false;
      }
    }
  }

  return true;
}

// @lc code=end

