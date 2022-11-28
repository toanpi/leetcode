/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define SIZE    100

#define add(l, r, i, len)    {ret[(len)][0] = nums[(l)]; ret[(len)][1] = nums[(r)];ret[(len)++][2] = nums[(i)];}

int cmp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int find(int *nums, int l, int r, int **ret, int *len)
{
  int sum = nums[l] + nums[r];

  for (int i = l + 1; i < r; i++)
  {
    if (nums[i] == -sum)
    {
      add(l, r, i, *len);
      break;
    }
  }

  return sum;
}

void sum2(int *nums, int left, int right, int **ret, int *len)
{
  int mid = 0;

  for (int i = left; i < right - 1; i++)
  {
    int k = -nums[i];
    int l = i + 1;
    int r = right;

    while (l < r)
    {
      mid = (l + r) / 2;

      int n = nums[l] + nums[r];

      if (n == k)
      {
        add(i, l, r, *len);
        // break;
      }
      else if (n < k)
      {
        
      }
      else
      {
      }
    }
  }
}

void search(int *nums, int l, int r, int **ret, int *len)
{
  while (l + 1 < r && nums[l] <= 0 && nums[r] >= 0)
  {
    int sum = find(nums, l, r, ret, len);

    if (sum == 0)
    {
      int i = l;
      
      while (++i + 1 < r && nums[i] == nums[i - 1]);
      find(nums, i, r, ret, len);

      i = r;
      while ((l + 1 < --i) && (nums[i] == nums[i + 1]));
      find(nums, l, i, ret, len);
    }

    if (sum >= 0)
    {
      while ((l + 1 < --r) && (nums[r] == nums[r + 1]));
    }

    if (sum <= 0)
    {
      while (++l + 1 < r && nums[l] == nums[l - 1]);
    }
  }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
  int **ret = malloc(SIZE * sizeof(int *));
  int *colSize = malloc(SIZE * sizeof(int));
  int len = 0;

  for (int i = 0; i < SIZE; i++)
  {
    ret[i] = malloc(3 * sizeof(int));
    colSize[i] = 3;
  }

  qsort(nums, numsSize, sizeof(int), cmp);

  // search(nums, 0, numsSize - 1, ret, &len);
  sum2(nums, 0, numsSize - 1, ret, &len);

  *returnSize = len;

  if (returnColumnSizes)
  {
    *returnColumnSizes = colSize;
  }

  return ret;
}

// @lc code=end

