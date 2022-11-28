/*
 * @lc app=leetcode id=541 lang=c
 *
 * [541] Reverse String II
 */

// @lc code=start

char *reverseStr(char *s, int k)
{
  int rLen = k;
  int remain = strlen(s);
  int i = 0;

  while (remain > 0)
  {
    char *p = &s[i];

    rLen = remain < k ? remain : k;

    for (int j = 0; j < rLen / 2; j++)
    {
      char temp = p[j];
      p[j] = p[rLen - 1 - j];
      p[rLen - 1 - j] = temp;
    }

    i += 2 * k;
    remain -= 2 * k;
  }

  return s;
}

// @lc code=end
