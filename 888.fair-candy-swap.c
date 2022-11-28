/*
 * @lc app=leetcode id=888 lang=c
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *fairCandySwap(int *aliceSizes, int aliceSizesSize,
                   int *bobSizes, int bobSizesSize,
                   int *returnSize)
{
  bool table[100001] = {0};
  int *ret = malloc(2 * sizeof(int));
  int numA = 0;
  int numB = 0;
  int goal = 0;

  for (int i = 0; i < aliceSizesSize; i++)
  {
    numA += aliceSizes[i];
  }

  for (int i = 0; i < bobSizesSize; i++)
  {
    numB += bobSizes[i];
    table[bobSizes[i]] = true;
  }

  goal = (numA + numB) / 2;

  for (int i = 0; i < aliceSizesSize; i++)
  {
    int bob = goal - numA + aliceSizes[i];

    if (bob > 0 && bob < 100000 && table[bob])
    {
      ret[0] = aliceSizes[i];
      ret[1] = bob;
      break;
    }
  }

  if (returnSize)
  {
    *returnSize = 2;
  }
  return ret;
}

// @lc code=end
