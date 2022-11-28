/*
 * @lc app=leetcode id=944 lang=c
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start

int minDeletionSize(char **strs, int strsSize)
{
  int cnt = 0;

  for (int i = 0; strs[0][i]; i++)
  {
    for (int j = 0; j < strsSize - 1; j++)
    {
      if (strs[j][i] > strs[j + 1][i])
      {
        cnt++;
        break;
      }
    }
  }

  return cnt;
}

// @lc code=end

