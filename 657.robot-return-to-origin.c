/*
 * @lc app=leetcode id=657 lang=c
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
bool judgeCircle(char *moves)
{
  int x = 0;
  int y = 0;

  for (int i = 0; moves[i]; i++)
  {
    y += (moves[i] == 'U') - (moves[i] == 'D');
    x += (moves[i] == 'R') - (moves[i] == 'L');
  }

  return x == 0 && y == 0;
}

// @lc code=end

