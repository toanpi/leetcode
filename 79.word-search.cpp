/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    bool compare(vector<vector<char>> &board, string word, int wi, int bi, int bj)
    {
        if (bi >= 0 && bi < board.size() &&
            bj >= 0 && bj < board[0].size() &&
            board[bi][bj] == word[wi])
        {
            if (wi + 1 < word.size())
            {
                char c = board[bi][bj];

                board[bi][bj] = 0;

                bool ret = compare(board, word, wi + 1, bi - 1, bj) ||
                           compare(board, word, wi + 1, bi + 1, bj) ||
                           compare(board, word, wi + 1, bi, bj - 1) ||
                           compare(board, word, wi + 1, bi, bj + 1);

                board[bi][bj] = c;

                return ret;
            }

            return true;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(compare(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end
