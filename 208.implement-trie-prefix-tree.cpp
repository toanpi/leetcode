/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include "cpp_h.h"

// @lc code=start
class Trie
{
public:
    char c;
    vector<Trie *> child;

    Trie()
    {
        c = 0;
        child = {};
    }

    Trie(char _c)
    {
        c = _c;
        child = {};
    }

    bool searchW(string &word, int *lastIdx, Trie **lastNode)
    {
        if (!searchHelp(word, lastIdx, lastNode))
        {
            return false;
        }

        for (auto n : (*lastNode)->child)
        {
            if (n->c == '#')
                return true;
        }

        return false;
    }

    bool searchHelp(string &word, int *lastIdx, Trie **lastNode)
    {
        auto pChild = child;

        for (int i = 0; i < word.size(); ++i)
        {
            int k = 0;

            for (; k < pChild.size(); ++k)
            {
                if (word[i] == pChild[k]->c)
                {
                    if (lastIdx) *lastIdx = i;
                    if (lastNode) *lastNode = pChild[k];
                    pChild = pChild[k]->child;
                    break;
                }
            }

            if (k == pChild.size())
            {
                return false;
            }
        }

        return true;
    }

    void insertHelp(string &word)
    {
        int lastIdx = -1;
        Trie *lastNode = nullptr;

        if (!searchW(word, &lastIdx, &lastNode))
        {
            vector<Trie *> *pChild = lastNode ? &lastNode->child : &child;

            for (int i = lastIdx + 1; i <= word.size(); ++i)
            {
                Trie *node = new Trie(word[i] ? word[i] : '#');
                pChild->push_back(node);
                pChild = &node->child;
            }
        }
    }

    void insert(string word)
    {
        return insertHelp(word);
    }

    bool search(string word)
    {
        Trie *node = nullptr;
        return searchW(word, nullptr, &node);
    }

    bool startsWith(string prefix)
    {
        return searchHelp(prefix, nullptr, nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
