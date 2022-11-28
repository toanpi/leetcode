/*
 * @lc app=leetcode id=883 lang=c
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start

int projectionArea(int **grid, int gridSize, int *gridColSize)
{
  int cnt = 0;

  for (int i = 0; i < gridSize; i++)
  {
    int maxRow = 0;
    int maxCol = 0;

    for (int j = 0; j < gridColSize[0]; j++)
    {
      if (grid[i][j] > maxRow) maxRow = grid[i][j];
      if (grid[j][i] > maxCol) maxCol = grid[j][i];
      if (grid[i][j] > 0) cnt++;
    }

    cnt += maxCol + maxRow;
  }

  return cnt;
}

// @lc code=end

