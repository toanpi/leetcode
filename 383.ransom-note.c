/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start
bool canConstruct(char *ransomNote, char *magazine)
{
  int letters[26] = {0};

  for (int i = 0; magazine[i]; i++)
  {
    letters[magazine[i] - 'a']++;
  }

  for (int i = 0; ransomNote[i]; i++)
  {
    if (--letters[ransomNote[i] - 'a'] < 0)
    {
      return false;
    }
  }

  return true;
}

// @lc code=end

