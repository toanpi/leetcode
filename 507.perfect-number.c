/*
 * @lc app=leetcode id=507 lang=c
 *
 * [507] Perfect Number
 */

// @lc code=start

bool isPrime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }

  return n >= 2;
}

bool checkPerfectNumber(int num)
{
  int p = 1;
  int val = 0;
  int d = 0;
  // an even number is perfect if and only if
  // it has the form 2^(p−1) * (2^(p) − 1),
  // where 2p − 1 is a prime number.
  while (val < num)
  {
    d = (1 << p) - 1;
    val = (1 << (p - 1)) * d;

    if (isPrime(d) && num == val)
    {
      return true;
    }

    p++;
  }

  return false;
}

// @lc code=end

