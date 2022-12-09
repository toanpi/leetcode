/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include "cpp_h.h"

// @lc code=start
class LRUCache
{
public:
    unordered_map<int, list<pair<int, int>>::iterator> db;
    list<pair<int, int>> lru;
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        db.reserve(capacity);
    }

    int get(int key)
    {
        if (db.find(key) != db.end())
        {
            lru.splice(lru.begin(), lru, db[key]);
            return db[key]->second;
        }

        return -1;
    }

    void put(int key, int value)
    {
        auto e = db.find(key);

        if (e == db.end())
        {
            if (db.size() >= cap)
            {
                auto back = lru.back();
                db.erase(back.first);
                lru.pop_back();
            }

            lru.push_front({key, value});
            db.insert({key, lru.begin()});
        }
        else
        {
            lru.splice(lru.begin(), lru, e->second);
            lru.front().second = value;
            e->second = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
