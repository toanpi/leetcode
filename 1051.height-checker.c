/*
 * @lc app=leetcode id=1051 lang=c
 *
 * [1051] Height Checker
 */

// @lc code=start

void swap(int* nums, int i, int j)
{
  nums[i] = (nums[i] + nums[j]) - (nums[j] = nums[i]);
}

int partition(int *nums, int l, int h)
{
  int pivot = nums[h];
  int i = l - 1;

  for (int j = l; j < h; j++)
  {
    if (nums[j] < pivot)
    {
      i++;
      swap(nums, i, j);
    }
  }

  swap(nums, i + 1, h);

  return i + 1;
}

void quicksort(int* nums, int l, int h)
{
  if ((!nums) || (l >= h))
  {
    return;
  }

  int pi = partition(nums, l, h);

  quicksort(nums, l, pi - 1);
  quicksort(nums, pi + 1, h);
}


// int expected[6];
int heightChecker(int* heights, int heightsSize)
{
  int expected[heightsSize];
  int count = 0;

  memcpy(expected, heights, heightsSize * sizeof(int));

  quicksort(expected, 0, heightsSize - 1);

  for (int i = 0; i < heightsSize; i++)
  {
    if (expected[i] != heights[i])
    {
      count++;
    }
  }

  return count;
}

// @lc code=end

