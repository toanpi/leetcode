/*
 * @lc app=leetcode id=682 lang=c
 *
 * [682] Baseball Game
 */

// @lc code=start

int calPoints(char **operations, int operationsSize)
{
  int sum = 0;
  int numCnt = 0;

  for (int i = 0; i < operationsSize; i++)
  {
    if (operations[i][0] == '+')
    {
      int val = atoi(operations[numCnt - 1]) + atoi(operations[numCnt - 2]);
      
      sum += val;

      operations[numCnt] = malloc(11);
      sprintf(operations[numCnt++], "%d", val);
    }
    else if (operations[i][0] == 'D')
    {
      int val = 2 * atoi(operations[numCnt - 1]);
      
      sum += val;
      
      operations[numCnt] = malloc(11);
      sprintf(operations[numCnt++], "%d", val);
    }
    else if (operations[i][0] == 'C')
    {
      sum -= atoi(operations[--numCnt]);
    }
    else
    {
      operations[numCnt++] = operations[i];
      sum += atoi(operations[i]);
    }
  }

  return sum;
}

// @lc code=end

