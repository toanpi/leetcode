/*
 * @lc app=leetcode id=1046 lang=c
 *
 * [1046] Last Stone Weight
 */

// @lc code=start

int compare(void *a, void *b)
{
  return (*(int *)a) - (*(int *)b);
}

int lastStoneWeight(int* stones, int stonesSize)
{
  int size = stonesSize;

  while (1)
  {
    if (size <= 1)
    {
      return stones[0];
    }

    qsort(stones, size, sizeof(int), compare);

    stones[size - 2] = stones[size - 1] - stones[size - 2];

    size = stones[size - 2] ? size - 1 : size - 2;
  }
}
// @lc code=end

