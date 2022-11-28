/*
 * @lc app=leetcode id=1122 lang=c
 *
 * [1122] Relative Sort Array
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
  int table[1001] = {0};
  int *out = malloc(arr1Size * sizeof(int));
  int idx = 0;

  memset(out, 0, arr1Size * sizeof(int));

  // Mark arr 2 element in table
  for (int i = 0; i < arr2Size; i++)
  {
    table[arr2[i]] = 1001;
  }

  for (int i = 0; i < arr1Size; i++)
  {
    table[arr1[i]]++;
  }

  // Set arr2 into output
  for (int i = 0; i < arr2Size; i++)
  {
    int num = table[arr2[i]] - 1001;

    for (int j = 0; j < num; j++)
    {
      out[idx++] = arr2[i];
    }
  }

  int remain = idx;

  // Set remain element that is not in array 2
  for (int i = 0; i < arr1Size; i++)
  {
    if (table[arr1[i]] < 1001)
    {
      out[idx++] = arr1[i];
    }
  }

  // Sort remain in acesding
  qsort(out + remain, idx - remain, sizeof(int), cmpfunc);

  if (returnSize)
  {
    *returnSize = arr1Size;
  }

  return out;
}

// @lc code=end

