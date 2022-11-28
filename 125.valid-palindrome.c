/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */

// @lc code=start
bool isPalindrome(char *s)
{
  int sLen = strlen(s);
  int l = 0;
  int r = sLen - 1;

  while (l < r)
  {
    while (l < r && !isalnum(s[l])) l++;
    while (l < r && !isalnum(s[r])) r--;

    if (tolower(s[l]) != tolower(s[r])) return false;

    l++;
    r--;
  }

  return true;
}

// @lc code=end

