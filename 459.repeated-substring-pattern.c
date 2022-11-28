/*
 * @lc app=leetcode id=459 lang=c
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start

bool repeatedSubstringPattern(char *s)
{
  int sLen = strlen(s);

  for (int subLen = 1; subLen <= sLen / 2; subLen++)
  {
    if ((sLen % subLen == 0) && !memcmp(s, &s[subLen], sLen - subLen))
    {
      return true;
    }
  }

  return false;
}

// @lc code=end

