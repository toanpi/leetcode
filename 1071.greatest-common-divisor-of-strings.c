/*
 * @lc app=leetcode id=1071 lang=c
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start

char *subS(char *s1, int len1, char *s2, int len2)
{
  if (len1 > len2 && !strncmp(s1, s2, len2))
  {
    return s1 + len2;
  }
  else if (!strncmp(s1, s2, len1))
  {
    return s2 + len1;
  }
  else
  {
    return NULL;
  }
}

char *gcdOfStrings(char *str1, char *str2)
{
  if (!strcmp(str1, str2))
  {
    return str1;
  }

  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *com = subS(str1, len1, str2, len2);
  char *s = len1 > len2 ? str2 : str1;

  return com ? gcdOfStrings(com, s) : "";
}

// @lc code=end

