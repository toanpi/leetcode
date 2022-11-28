/*
 * @lc app=leetcode id=1037 lang=c
 *
 * [1037] Valid Boomerang
 */

// @lc code=start

bool isBoomerang(int **points, int pointsSize, int *pointsColSize)
{
  /*
    y = ax + b
    y1 = ax1 + b
    y2 = ax2 + b

    --> a = (y2 - y1) / (x2 - x1)
    --> b = y1 - x1 * (y2 - y1) / (x2 - x1)

    --> if y3 == ax3 + b --> true
    --> y3 == x3 * (y2 - y1) / (x2 - x1) +  y1 - x1 * (y2 - y1) / (x2 - x1)
    --> y3 * (x2 - x1) == x3 * (y2 - y1) + y1 * (x2 - x1) - x1 * (y2 - y1)
                       == (y2 - y1)(x3 - x1) + y1 * (x2 - x1)

  */
  int x1 = points[0][0];
  int x2 = points[1][0];
  int x3 = points[2][0];
  int y1 = points[0][1];
  int y2 = points[1][1];
  int y3 = points[2][1];

  return !((y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1));
}

// @lc code=end
