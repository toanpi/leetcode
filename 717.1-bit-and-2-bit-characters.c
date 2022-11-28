/*
 * @lc app=leetcode id=717 lang=c
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start

bool isOneBitCharacter(int *bits, int bitsSize)
{
  if (bitsSize <= 1)
  {
    return (bitsSize == 1) && (bits[0] == 0);
  }

  if (bits[0])
  {
    return isOneBitCharacter(&bits[2], bitsSize - 2);
  }
  else
  {
    return isOneBitCharacter(&bits[1], bitsSize - 1);
  }
}

// @lc code=end
