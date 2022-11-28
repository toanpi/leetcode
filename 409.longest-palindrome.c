/*
 * @lc app=leetcode id=409 lang=c
 *
 * [409] Longest Palindrome
 */

// @lc code=start

int longestPalindrome(char *s)
{
  int table[128] = {0};

  for (int i = 0; s[i]; i++)
  {
    table[s[i]]++;
  }

  int len = 0;
  bool hasOdd = false;

  for (int i = 0; i < 128; i++)
  {
    len += table[i] - (table[i] % 2);

    if (!hasOdd && (table[i] % 2))
    {
      hasOdd = true;
    }
  }

  return len + (hasOdd ? 1 : 0);
}

// @lc code=end
