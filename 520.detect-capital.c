/*
 * @lc app=leetcode id=520 lang=c
 *
 * [520] Detect Capital
 */

// @lc code=start



bool detectCapitalUse(char *word)
{
  if (islower(word[0]) && isupper(word[1]))
  {
    return false;
  }

  bool needLower = islower(word[1]);

  for (int i = 1; word[i]; i++)
  {
    if (needLower != (islower(word[i]) > 0))
    {
      return false;
    }
  }

  return true;
}

// @lc code=end

