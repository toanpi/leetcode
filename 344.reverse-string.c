/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start

void reverseString(char *s, int sSize)
{
  int mid = sSize / 2;
  char temp = 0;

  for (int i = 0; i < mid; i++)
  {
    temp = s[i];
    s[i] = s[sSize - 1 - i];
    s[sSize - 1 - i] = temp;
  }
}

// @lc code=end

