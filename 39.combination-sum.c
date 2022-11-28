/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE      150

void combination(int *combine, int *combSize, int *candidates, int candidatesSize, int target,
                 int *returnSize, int *returnColumnSizes, int **resArray)
{
  // Input: candidates = [2,3,6,7], target = 7
  // Output: [[2,2,3],[7]]
  // [2][2,3,6,7] - 5 -> [2, 2][2,3,6,7] - 3 -> [2, 2, 2][2,3,6,7] - 1 -> [2, 2, 2, 2] -> X
  //                                                                   -> [2, 2, 2, 3] -> X
  //                                                                   -> [2, 2, 2, 6] -> X
  //                                                                   -> [2, 2, 2, 7] -> X
  //
  //                                            [2, 2, 3][3,6,7] - 0 -> OK
  //                                            [2, 2, 6][6,7] -> X
  //                                            [2, 2, 7][7] -> X
  //
  //                      -> [2, 3][3,6,7] - 2 -> [2, 3, 3][3,6,7] -> X
  //                      -> [2, 3][3,6,7] - 2 -> [2, 3, 6][6,7] -> X
  //                      -> [2, 3][3,6,7] - 2 -> [2, 3, 7][7] -> X
  //
  // [3][3,6,7] - 4 -> [3, 3][3,6,7] - 1 -> [3, 3, 3][3,6,7] -> X
  //                                     -> [3, 3, 6][6,7] -> X
  //                                     -> [3, 3, 7][7] -> X
  //
  // [6][6,7] - 1 -> [6, 6][6,7] -> X
  //              -> [6, 7][7] -> X
  //
  // [7] -> [7] - 0 --> OK
  //

  if (target == 0)
  {
    if (*combSize && combine && resArray[*returnSize])
    {
      // Copy to response
      memcpy(resArray[*returnSize], combine, (*combSize) * sizeof(int));
    }

    returnColumnSizes[*returnSize] = *combSize;
    (*returnSize)++;
  }

  // Loop for each candidate
  for (int i = 0; i < candidatesSize; i++)
  {
    if (candidates[i] > target)
    {
      continue;
    }

    combine[(*combSize)] = candidates[i];

    (*combSize)++;

    // Call recursion function here
    combination(combine, combSize, &candidates[i], candidatesSize - i, target - candidates[i],
                returnSize, returnColumnSizes, resArray);
  
    (*combSize)--;
  }
}



int **combinationSum(int *candidates, int candidatesSize,
                     int target, int *returnSize, int **returnColumnSizes)
{
  int arr[MAX_SIZE][target];
  int g_combine[MAX_SIZE] = {0};
  int resColSize[MAX_SIZE] = {0};
  int *res[MAX_SIZE] = {0};
  int columSize = 0;
  int combineSize = 0;

  for (int i = 0; i < MAX_SIZE; i++)
  {
    memset(&arr[i], 0, sizeof(arr[i]));
    res[i] = &arr[i];
  }

  combination(g_combine, &combineSize, candidates, candidatesSize, target, &columSize, resColSize, res);

  if (returnSize)
  {
    *returnSize = columSize;
  }

  if (returnColumnSizes)
  {
    *returnColumnSizes = resColSize;
  }

  return res;
}


// @lc code=end

