/*
 * @lc app=leetcode id=914 lang=c
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start

#define SIZE 10000

int gcd(int a, int b)
{
  if (a == 0)
  {
    return b;
  }

  return gcd(b % a, a);
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
  int table[SIZE] = {0};
  bool ret = true;
  int g = -1;

  for (int i = 0; i < deckSize; i++)
  {
    table[deck[i]]++;
  }

  for (int i = 0; i < SIZE; i++)
  {
    if (table[i])
    {
      if (g < 0)
      {
        g = table[i];
      }
      else
      {
        g = gcd(g, table[i]);
      }

      if (g < 2)
      {
        ret = false;
        break;
      }
    }
  }

  return ret;
}

// @lc code=end

