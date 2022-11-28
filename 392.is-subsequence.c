/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 */

// @lc code=start


bool isSubsequence(char * s, char * t)
{
  // s = "abc", t = "ahbgdc" -> true
  // s = "axc", t = "ahbgdc" -> false
  int si = 0;
  int ti = 0;
  int s_len = strlen(s);
  int t_len = strlen(t);
  bool ret = true;

  for (si = 0; si < s_len; si++)
  {
    bool found = false;

    for (; ti < t_len; ti++)
    {
      if (t[ti] == s[si])
      {
        found = true;
        ti++;
        break;
      }
    }

    if (!found)
    {
      // Not matched
      ret = false;
      break;
    }
  }

  return ret;
}
// @lc code=end
