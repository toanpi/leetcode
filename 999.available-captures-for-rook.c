/*
 * @lc app=leetcode id=999 lang=c
 *
 * [999] Available Captures for Rook
 */

// @lc code=start


int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
  int count = 0;
  int i = 0;
  int j = 0;
  char pre_char = 0;

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      if(board[i][j] == 'R')
      {
        // Found rook
        break;
      }
    }
  }
  
  // Check row
  for (int c = 0; c < 8; c++)
  {
    if(board[i][c] != '.')
    {
      if (pre_char +  board[i][c] == 'R' + 'p')
      {
        count++;
      }
      pre_char = board[i][c];
    }
  }

  pre_char = 0;

  // Check column
  for (int c = 0; c < 8; c++)
  {
    if(board[c][j] != '.')
    {
      if (pre_char +  board[c][j] == 'R' + 'p')
      {
        count++;
      }
      pre_char = board[c][j];
    }
  }
  
  return count;
}
// @lc code=end

