/*
 * @lc app=leetcode id=521 lang=c
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start

int findLUSlength(char *a, char *b)
{
  if (strcmp(a, b))
  {
    int lenA = strlen(a);
    int lenB = strlen(b);
    return lenA < lenB ? lenB : lenA;
  }
  else
  {
    return -1;
  }
}

// @lc code=end

