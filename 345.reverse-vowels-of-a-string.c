/*
 * @lc app=leetcode id=345 lang=c
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

#define isVowels(c) ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')

char *reverseVowels(char *s)
{
  int sLen = strlen(s);
  int l = 0;
  int r = sLen - 1;

  while (l < r)
  {
    while (l < r && !isVowels(tolower(s[l]))) l++;
    while (l < r && !isVowels(tolower(s[r]))) r--;

    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    l++;
    r--;
  }

  return s;
}

// @lc code=end

