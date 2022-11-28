/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 */

// @lc code=start

#define TOP       (0)
#define RIGHT     (1)
#define BOTTOM    (2)
#define LEFT      (3)

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
  int perimeter = 0;

  for (int i = 0; i < gridSize; i++)
  {
    for (int j = 0; j < gridColSize[i]; j++)
    {
      if (grid[i][j])
      {
        perimeter += 4;
        perimeter -= (j + 1 < gridColSize[i]) ? 2 * grid[i][j + 1] : 0;
        perimeter -= (i + 1 < gridSize) ? 2 * grid[i + 1][j] : 0;
      }
    }
  }

  return perimeter;
}

// @lc code=end
