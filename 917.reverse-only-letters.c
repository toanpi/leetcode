/*
 * @lc app=leetcode id=917 lang=c
 *
 * [917] Reverse Only Letters
 */

// @lc code=start

void swap(char *s, int x, int y)
{
  char temp = s[x];
  s[x] = s[y];
  s[y] = temp;
}

bool isLetter(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char * reverseOnlyLetters(char * s)
{
  // Input: s = "Test1ng-Leet=code-Q!"
  // Output: "Qedo1ct-eeLg=ntse-T!"
  int l = 0;
  int r = strlen(s) - 1;

  while (l < r)
  {
    // left char
    while (!isLetter(s[l]) && l < r)
    {
      l++;
    }

    // right char
    while (!isLetter(s[r]) && (r > l))
    {
      r--;
    }

    if (l < r)
    {
      swap(s, l, r);
    }

    r--;
    l++;
  }

  return s;
}

// @lc code=end

