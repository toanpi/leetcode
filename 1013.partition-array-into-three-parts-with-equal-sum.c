/*
 * @lc app=leetcode id=1013 lang=c
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
bool canThreePartsEqualSum(int *arr, int arrSize)
{
  int sum = 0;
  int i = 0;

  while (i < arrSize) sum += arr[i++];

  if (sum % 3)
  {
    return false;
  }

  sum /= 3;

  int n = 0;
  int cnt = 0;

  for (i = 0; i < arrSize; i++)
  {
    n += arr[i];

    if (n == sum)
    {
      n = 0;
      cnt++;
    }
  }

  return cnt >= 3;
}

// @lc code=end

