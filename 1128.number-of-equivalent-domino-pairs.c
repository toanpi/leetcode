/*
 * @lc app=leetcode id=1128 lang=c
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
  int table[100] = {0};
  int count = 0;

  for (int i = 0; i < dominoesSize; i++)
  {
    int d = dominoes[i][0] * 10 + dominoes[i][1];

    if (dominoes[i][1] < dominoes[i][0])
    {
      d = dominoes[i][1] * 10 + dominoes[i][0];
    }

    if (table[d])
    {
      count += table[d];
    }

    table[d]++;
  }

  return count;
}
// @lc code=end

