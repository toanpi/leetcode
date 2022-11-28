/*
 * @lc app=leetcode id=942 lang=c
 *
 * [942] DI String Match
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *diStringMatch(char *s, int *returnSize)
{
  int n = strlen(s);
  int *ret = malloc((n + 1) * sizeof(int));
  int size = 0;
  int l = 0;
  int r = n;

  for (int i = 0; s[i]; i++)
  {
    if (s[i] == 'I')
    {
      ret[size++] = l++;
    }
    else
    {
      ret[size++] = r--;
    }
  }

  ret[size] = l;

  if (returnSize)
  {
    *returnSize = n + 1;
  }
  return ret;
}

// @lc code=end
