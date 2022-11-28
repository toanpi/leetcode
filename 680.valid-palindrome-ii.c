/*
 * @lc app=leetcode id=680 lang=c
 *
 * [680] Valid Palindrome II
 */

// @lc code=start

// ebcbb ec e cabba c ec bbcbe

bool isPalindrome(char *s, int l, int r, int *lastL, int *lastR)
{
  while (l < r)
  {
    if (s[l++] != s[r--])
    {
      if (lastL) *lastL = l - 1;
      if (lastR) *lastR = r + 1;
      return false;
    }
  }
  return true;
}

bool validPalindrome(char *s)
{
  int l = 0;
  int r = 0;

  return isPalindrome(s, 0, strlen(s) - 1, &l, &r) ||
         isPalindrome(s, l + 1, r, NULL, NULL) ||
         isPalindrome(s, l, r - 1, NULL, NULL);
}

// @lc code=end

