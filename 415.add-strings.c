/*
 * @lc app=leetcode id=415 lang=c
 *
 * [415] Add Strings
 */

// @lc code=start

char *addStrings(char *num1, char *num2)
{
  int i = strlen(num1);
  int j = strlen(num2);
  char *sum = calloc(i > j ? i + 2 : j + 2, sizeof(char));
  int idx = i > j ? i : j;
  int n = 0;

  while (n || i || j )
  {
    n += i ? num1[--i] - '0' : 0;
    n += j ? num2[--j] - '0' : 0;

    sum[idx--] = (n % 10) + '0';

    n /= 10;
  }

  return sum + idx + 1;
}

// @lc code=end

