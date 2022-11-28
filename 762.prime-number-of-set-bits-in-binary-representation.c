/*
 * @lc app=leetcode id=762 lang=c
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start

bool isPrime(int n)
{
  if (n >= 2)
  {
    for (int i = 2; i <= sqrt(n); i++)
    {
      if ((n % i) == 0)
      {
        return false;
      }
    }

    return true;
  }

  return false;
}

bool isSmallPrime(int x)
{
  return (x == 2 || x == 3 || x == 5 || x == 7 ||
          x == 11 || x == 13 || x == 17 || x == 19);
}

int countBits(int n)
{
  int cnt = 0;
  int mr1b = n & (~(n - 1));

  while (mr1b)
  {
    cnt++;
    n &= ~mr1b;
    mr1b = n & (~(n - 1));
  }

  return cnt;
}

int countPrimeSetBits(int left, int right)
{
  int cnt = 0;

  for (int i = left; i <= right; i++)
  {
    cnt += isSmallPrime(countBits(i)) ? 1 : 0;
    // cnt += isPrime(countBits(i)) ? 1 : 0;
  }

  return cnt;
}

// @lc code=end

