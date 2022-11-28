/*
 * @lc app=leetcode id=551 lang=c
 *
 * [551] Student Attendance Record I
 */

// @lc code=start

bool checkRecord(char *s)
{
  int absentCnt = 0;
  int lateCnt = 0;

  for (int i = 0; s[i]; i++)
  {
    absentCnt += (s[i] == 'A');

    lateCnt = (s[i] == 'L') * (lateCnt + 1);

    if (absentCnt >= 2 || lateCnt >= 3)
    {
      return false;
    }
  }

  return true;
}

// @lc code=end
