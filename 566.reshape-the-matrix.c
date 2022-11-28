/*
 * @lc app=leetcode id=566 lang=c
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixReshape(int **mat, int matSize, int *matColSize,
                    int r, int c,
                    int *returnSize, int **returnColumnSizes)
{
  if ((r * c) != (matSize * matColSize[0]))
  {
    int *col = malloc(matSize * sizeof(int));

    for (int i = 0; i < matSize; i++)
    {
      col[i] = matColSize[0];
    }

    *returnSize = matSize;
    *returnColumnSizes = col;
    return mat;
  }

  int **ret = malloc(r * sizeof(int *));
  int *col = malloc(r * sizeof(int));
  int rIdx = 0;
  int cIdx = 0;

  for (int i = 0; i < r; i++)
  {
    ret[i] = malloc(c * sizeof(int));
    col[i] = c;
  }

  for (int i = 0; i < matSize; i++)
  {
    for (int j = 0; j < matColSize[i]; j++)
    {
      ret[rIdx][cIdx++] = mat[i][j];

      if (cIdx == c)
      {
        rIdx++;
        cIdx = 0;
      }
    }
  }

  *returnSize = r;
  *returnColumnSizes = col;
  return ret;
}

// @lc code=end

