/*
 * @lc app=leetcode id=830 lang=c
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **largeGroupPositions(char *s, int *returnSize, int **returnColumnSizes)
{
  int strLen = strlen(s);
  int **ret = malloc((strLen / 3 + 1) * sizeof(int *));
  int *sizeRow = malloc((strLen / 3 + 1) * sizeof(int));
  int size = 0;
  int cnt = 1;
  int start = 0;

  for (int i = 0; i < strLen; i++)
  {
    if (s[i] == s[i + 1])
    {
      cnt++;
    }
    else
    {
      if (cnt >= 3)
      {
        ret[size] = malloc(2 * sizeof(int));
        ret[size][0] = start;
        ret[size][1] = i;
        sizeRow[size] = 2;
        size++;
      }

      cnt = 1;
      start = i + 1;
    }
  }

  if(returnSize) *returnSize = size;
  if(returnColumnSizes) *returnColumnSizes = sizeRow;
  return ret;
}

// @lc code=end

