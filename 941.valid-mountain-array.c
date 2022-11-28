/*
 * @lc app=leetcode id=941 lang=c
 *
 * [941] Valid Mountain Array
 */

// @lc code=start

bool validMountainArray(int *arr, int arrSize)
{
  int status = 0;

  for (int i = 0; i < arrSize - 1; i++)
  {
    if (arr[i] < arr[i + 1])
    {
      if (status == 2)
      {
        return false;
      }

      status = 1;
    }

    if (arr[i] > arr[i + 1])
    {
      if (status == 0)
      {
        return false;
      }
     
      status = 2;
    }

    if (arr[i] == arr[i + 1])
    {
      return false;
    }
  }

  return status == 2;
}

// @lc code=end

