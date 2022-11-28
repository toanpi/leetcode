/*
 * @lc app=leetcode id=859 lang=c
 *
 * [859] Buddy Strings
 */

// @lc code=start


bool buddyStrings(char * s, char * goal)
{

  if (!s || !goal)
  {
    return false;
  }

  // s = "ab", goal = "ba" -> Swap 0 - 1
  // s = "ab", goal = "ab" -> False
  // s = "aa", goal = "aa" --> Swap 0 - 1
  // "abcd", goal "cbad" -> Swap 0 - 2
  // "baca", goal "baca" -> Swap 0 - 3

  int len = strlen(s);
  int idx_0 = -1;
  int idx_1 = -1;
  bool ret = false;
  int table[128] = {0};
  bool is_duplicated = false;


  if (strlen(goal) != len)
  {
    return false;
  }

  for (int i = 0; i < len; i++)
  {
    table[s[i]]++;
    
    if (table[s[i]] > 1)
    {
      is_duplicated = true;
    }

    if (s[i] != goal[i])
    {
      if (idx_0 < 0)
      {
        idx_0 = i;
      }
      else if (idx_1 < 0)
      {
        idx_1 = i;
      }
      else if (ret == true)
      {
        // Found --> but the remain is different
        ret = false;
        break;
      }
    }

    if (idx_0 >= 0 && idx_1 >= 0)
    {
      ret = (s[idx_0] == goal[idx_1]) && (s[idx_1] == goal[idx_0]);
    }
  }

  // The same
  if (idx_0 < 0 && idx_1 < 0)
  {
    // Check duplication
    ret = is_duplicated;
  }

  return ret;
}
// @lc code=end

