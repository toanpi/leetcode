/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start

#define toSheet(n) ((n) ? ((n)-1 + 'A') : 'Z')

char *convertToTitle(int columnNumber)
{
  int idx = 10;
  char *ret = calloc(idx + 2, sizeof(char));
  int remain = columnNumber;

  while (remain > 0)
  {
    int val = (remain % 26) ? (remain % 26) : 26;

    ret[idx--] = toSheet(val);

    remain -= val;
    remain /= 26;
  }

  return &ret[idx + 1];
}

// @lc code=end

