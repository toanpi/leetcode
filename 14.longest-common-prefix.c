/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize)
{
  char *pre = malloc((strlen(strs[0]) + 1) * sizeof(char));
  strcpy(pre, strs[0]);

  for (int i = 1; i < strsSize; i++)
  {
    if ((*pre) == '\0')
    {
      break;
    }

    char *s = strs[i];
    char *prefix = pre;

    while (true)
    {
      if ((*prefix) != (*s) || ((*s) == '\0') || ((*prefix) == '\0'))
      {
        *prefix = '\0';
        break;
      }

      prefix++;
      s++;
    }
  }

  return pre;
}
// @lc code=end

