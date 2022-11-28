/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

char * longestPalindrome(char * s)
{

  int max = 1;
  // int map[128];
  int len = strlen(s);
  int lo_idx = 0;
  int hi_idx = 0;

  if (len <= 1)
  {
    return s;
  }

  char rs[1000];

  for (int i = 0; i < len; i++)
  {
    rs[i] = s[len - 1 - i];
  }

  // Input: s = "bbcdadcbb ad"
  // 0 1 2 3 2 1 0
  // 0 0 1 2 3 2 1 0 0
  // "bab ad" --> bab
  // 012 3 210 78785

  // s = "bab000mmc" --> reverse rs = "cmm000bab"
  // b --> Find next b --> Compare b on s and rs
  // "[b] ab [a] d" --> bab

  for (int i = 0; i < len - 1; i++)
  {
    int start = i + max;

    for (int j = start; j < len; j++)
    {
      // Find repeating character
      if (s[j] == s[i])
      {
        int size = j - i + 1;

        if (!memcmp(&s[i], &rs[len - 1 - j], size))
        {
          // Update max here;
          if (size > max)
          {
            max = size;
            lo_idx = i;
            hi_idx = j;
          }
        }
      }
    }
  }

  s[lo_idx + max] = 0;

  return &s[lo_idx];
}



// @lc code=end

