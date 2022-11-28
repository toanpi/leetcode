/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start



typedef struct {
  int *tree;
  int numsSize;
} NumArray;

NumArray arr = {0};

NumArray* numArrayCreate(int* nums, int numsSize)
{
  int *tree = calloc(numsSize * 2, sizeof(int));

  memcpy(tree, nums, numsSize * sizeof(int));

  for (int i = numsSize, j = 0; i < 2 * numsSize - 1; i++, j += 2)
  {
    tree[i] = tree[j] + tree[j + 1];
  }

  arr.numsSize = numsSize;
  arr.tree = tree;

  return &arr;
}

int numArraySumRange(NumArray* obj, int left, int right)
{
  int sum = 0;
  int l = left;
  int r = right;

  while (l < r)
  {
    if (l % 2)
    {
      sum += obj->tree[l];
      l++;
    }

    l = l / 2 + obj->numsSize;

    if (r % 2 == 0)
    {
      sum += obj->tree[r];
      r--;
    }

    r = r / 2 + obj->numsSize;
  }

  if (l == r)
  {
    sum += obj->tree[l];
  }

  return sum;
}

void numArrayFree(NumArray* obj)
{
  free(obj->tree);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/

// @lc code=end

