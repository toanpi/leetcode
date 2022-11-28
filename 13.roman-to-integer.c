/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start


int romanToInt(char * s)
{
  int list[] =
      {
          ['I'] = 1,
          ['V'] = 5,
          ['X'] = 10,
          ['L'] = 50,
          ['C'] = 100,
          ['D'] = 500,
          ['M'] = 1000,
      };

  int val = 0;

  while (*s)
  {
    char c = *s;
    char next = *(s + 1);

    if (next && list[next] > list[c])
    {
      val += list[next] - list[c];
      s += 2;
    }
    else
    {
      val += list[c];
      s++;
    }
  }

  return val;
}
// @lc code=end

