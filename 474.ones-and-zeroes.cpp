/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maxForm(vector<pair<int, int>> &db, int idx, int m, int n,
                vector<vector<vector<int>>> &dp)
    {
        if (idx >= db.size() || m < 0 || n < 0)
        {
            return 0;
        }

        if (dp[idx][m][n] != -1)
        {
            return dp[idx][m][n];
        }

        int maxL = maxForm(db, idx + 1, m, n, dp);

        if (m >= db[idx].first && n >= db[idx].second)
        {
            maxL = max(maxL, 1 + maxForm(db, idx + 1, m - db[idx].first, n - db[idx].second, dp));
        }

        return dp[idx][m][n] = maxL;
    }

    int findMax(vector<string> &strs, int m, int n)
    {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 0; i < strs.size(); i++)
        {
            int n0 = count(strs[i].begin(), strs[i].end(), '0');
            int n1 = strs[i].size() - n0;

            for (int j = m; j >= 0; j--)
            {
                for (int k = n; k >= 0; k--)
                {
                    dp[i][j][k] = ((i >= 1) ? dp[i - 1][j][k] : 0);

                    if (j >= n0 && k >= n1)
                    {
                        dp[i][j][k] = max(dp[i][j][k], 1 + ((i >= 1) ? dp[i - 1][j - n0][k - n1] : 0));
                    }
                }
            }
        }

        return dp[strs.size() - 1][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        return findMax(strs, m, n);

        // vector<pair<int, int>> db;
        // vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        // for (int i = strs.size() - 1; i >= 0; i--)
        // {
        //     int n0 = 0;
        //     int n1 = 0;

        //     for (int j = 0; j < strs[i].size(); j++)
        //     {
        //         strs[i][j] == '0' ? n0++ : n1++;
        //     }
        //     db.push_back({n0, n1});
        // }

        // return maxForm(db, 0, m, n, dp);
    }
};
// @lc code=end
