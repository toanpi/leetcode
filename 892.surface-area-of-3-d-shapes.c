/*
 * @lc app=leetcode id=892 lang=c
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
#define min(a, b) ((a) < (b) ? (a) : (b))

int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
  int cnt = 0;

  for (int i = 0; i < gridSize; i++)
  {
    for (int j = 0; j < gridSize; j++)
    {
      if (grid[i][j] == 0)
      {
        continue; // No cue
      }

      cnt += 2 + 4 * grid[i][j]; // above + below + 4 around

      // Top neighbor
      if (i > 0) cnt -= min(grid[i - 1][j], grid[i][j]);

      // Bottom neighbor
      if (i < gridSize - 1) cnt -= min(grid[i + 1][j], grid[i][j]);

      // Left neighbor
      if (j > 0) cnt -= min(grid[i][j - 1], grid[i][j]);

      // Right neighbor
      if (j < gridSize - 1) cnt -= min(grid[i][j + 1], grid[i][j]);
    }
  }

  return cnt;
}
// @lc code=end

