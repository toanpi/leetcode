/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int *height, int heightSize)
{
  int maxA = 0;
  int l = 0;
  int r = heightSize - 1;

  while (l < r)
  {
    int a = (r - l) * min(height[l], height[r]);
    maxA = max(maxA, a);

    if(height[r] > height[l])
    {
      int h = height[l];
      while ((l < r) && (height[l] <= h)) l++;
    }
    else
    {
      int h = height[r];
      while ((l < r) && (height[r] <= h)) r--;
    }
  }
  

  return maxA;
}

// @lc code=end

