/*
 * @lc app=leetcode id=434 lang=c
 *
 * [434] Number of Segments in a String
 */

// @lc code=start

int countSegments(char *s)
{
  int cnt = 0;
  char *p = strtok(s, " ");

  while (p)
  {
    cnt++;
    p = strtok(NULL, " ");
  }

  return cnt;
}

// @lc code=end

