/*
 * @lc app=leetcode id=561 lang=c
 *
 * [561] Array Partition
 */

// @lc code=start

#define BASE   10000
#define SIZE  (2 * BASE + 1)

int arrayPairSum(int *nums, int numsSize)
{
  int sum = 0;
  int table[SIZE];
  int max = -BASE - 1;
  int min = BASE + 1;

  memset(table, 0, sizeof(table));

  for (int i = 0; i < numsSize; i++)
  {
    table[nums[i] + BASE]++;
  
    if(nums[i] > max) max = nums[i];
    if(nums[i] < min) min = nums[i];
  }

  for (int i = min + BASE, k = 0; i <= max + BASE; i++)
  {
    while (table[i] > 0)
    {
      if (k % 2 == 0)
      {
        sum += i - BASE;
      }

      k++;
      table[i]--;
    }
  }

  return sum;
}

// @lc code=end

