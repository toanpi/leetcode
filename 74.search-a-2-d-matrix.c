/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start

bool searchHelp(int **matrix, int lo, int hi, int n, int target)
{
  if (lo > hi)
  {
    return false;
  }
  // 0 - 1
  int mid = (lo + hi) / 2;
  int mid_row = mid / n;
  int mid_col = mid % n;

  if (matrix[mid_row][mid_col] == target)
  {
    return true;
  }
  else if (matrix[mid_row][mid_col] > target)
  {
    return searchHelp(matrix, lo, mid - 1, n, target);
  }
  else
  {
    return searchHelp(matrix, mid + 1, hi, n, target);
  }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
  int size = matrixSize * (* matrixColSize);

  return searchHelp(matrix, 0, size - 1, *matrixColSize, target);
}

// @lc code=end

