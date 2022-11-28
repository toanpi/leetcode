/*
 * @lc app=leetcode id=746 lang=c
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#define min(a, b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int *cost, int costSize)
{
  int i = 2;

  for (i = 2; i < costSize; i++)
  {
    cost[i] += min(cost[i - 1], cost[i - 2]);
  }

  return min(cost[i - 1], cost[i - 2]);
}

// @lc code=end

