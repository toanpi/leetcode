/*
 * @lc app=leetcode id=933 lang=c
 *
 * [933] Number of Recent Calls
 */

// @lc code=start

#define CAP     3001

typedef struct
{
  int time[CAP];
  int w;
  int r;
} RecentCounter;

RecentCounter *recentCounterCreate()
{
  return calloc(1, sizeof(RecentCounter));
}

void add(RecentCounter *obj, int t)
{
  obj->time[obj->w] = t;

  obj->w = (obj->w + 1) % CAP;

  if (obj->w == obj->r)
  {
    obj->r = (obj->r + 1) % CAP;
  }
}

int len(RecentCounter *obj)
{
  if (obj->w >= obj->r)
  {
    return obj->w - obj->r;
  }
  return CAP + obj->w - obj->r;
}

int count(RecentCounter *obj, int t)
{
  while (obj->r != obj->w && (t - obj->time[obj->r] > 3000))
  {
    obj->r = (obj->r + 1) % CAP;
  }

  return len(obj);
}

int recentCounterPing(RecentCounter *obj, int t)
{
  add(obj, t);

  return count(obj, t);
}

void recentCounterFree(RecentCounter *obj)
{
  free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
// @lc code=end

