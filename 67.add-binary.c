/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start
#define toBit(a)    ((a) == '1' ? 1 : 0)

char *addBinary(char *a, char *b)
{
  int lenA = strlen(a);
  int lenB = strlen(b);
  int idx = lenA > lenB ? lenA + 1 : lenB + 1;
  char *ret = calloc(idx + 2, sizeof(char));
  int n = 0;
  int i = lenA - 1;
  int j = lenB - 1;

  do
  {
    n += i >= 0 ? toBit(a[i--]) : 0;
    n += j >= 0 ? toBit(b[j--]) : 0;

    ret[idx--] = (n & 1) + '0';

    n = (n >> 1) & 1;

  } while (n || (i >= 0) || (j >= 0));

  return &ret[idx + 1];
}

// @lc code=end
