/*
 * @lc app=leetcode id=307 lang=c
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start

typedef struct
{
  int *arr;
  int *sumArr;
  int size;
  int *delta;
  int startDelta;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
}

void numArrayUpdate(NumArray *obj, int index, int val)
{
}

int numArraySumRange(NumArray *obj, int left, int right)
{
}

void numArrayFree(NumArray *obj)
{
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);

 * int param_2 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
// @lc code=end
