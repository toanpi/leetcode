/*
 * @lc app=leetcode id=925 lang=c
 *
 * [925] Long Pressed Name
 */

// @lc code=start

bool isLongPressedName(char *name, char *typed)
{
  int i = 0;
  int j = 0;

  while (name[i] || typed[j])
  {
    int cntN = name[i] ? 1 : 0;
    int cntT = typed[j] ? 1 : 0;

    while (name[i] && name[i] == name[i + 1])
    {
      cntN++;
      i++;
    }

    while (typed[j] && typed[j] == typed[j + 1])
    {
      cntT++;
      j++;
    }

    if (name[i] != typed[j] || cntT < cntN)
    {
      return false;
    }

    i++;
    j++;
  }

  return true;
}



// @lc code=end

