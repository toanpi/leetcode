/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */
#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

        int n = num;
        vector<int> db;
        int maxPos = -1;
        int maxVal = -1;
        int idx1 = -1;
        int idx2 = -1;

        while (n)
        {
            int val = n % 10;

            db.push_back(val);

            if(val > maxVal)
            {
                maxVal = val;
                maxPos = db.size() - 1;
            }
            else if(val < maxVal)
            {
                idx1 = db.size() - 1;
                idx2 = maxPos;
            }
            
            n /= 10;
        }

        if(idx1 >= 0 && idx2 >= 0)
        {
            swap(db[idx1], db[idx2]);
        }

        n = 0;
        for (int i = db.size() - 1; i >= 0; i--)
        {
            n *= 10;
            n += db[i];
        }

        return n;
    }
};

// @lc code=end
