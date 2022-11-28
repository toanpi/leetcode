/*
 * @lc app=leetcode id=290 lang=c
 *
 * [290] Word Pattern
 */

// @lc code=start

typedef struct
{
  char *word;
  int len;
} word;

#define NUM_LETTERS     26

word getWord(char *s)
{
  word w = {.word = s};
  char *ps = s;

  while (((*ps) != ' ') && ((*ps) != NULL))
  {
    w.len++;
    ps++;
  }

  return w;
}

bool wordPattern(char * pattern, char * s)
{
  bool ret = true;
  word letters[NUM_LETTERS] = {0};
  int pattern_len = strlen(pattern);
  char *pw = s;

  for (int i = 0; i < pattern_len; i++)
  {
    word w = getWord(pw);
    word *pre = &letters[pattern[i] - 'a'];

    if (w.len == 0)
    {
      // No word found
      ret = false;
      break;
    }

    if (pre->word)
    {
      // Existing --> compare current word with stored word
      if ((pre->len != w.len) || (memcmp(w.word, pre->word, w.len) != 0))
      {
        ret = false;
        break;
      }
    }
    else
    {
      // Check if w is existing with different letter --> If yes --> return false
      for (int j = 0; j < NUM_LETTERS; j++)
      {
        if (letters[j].word &&
            (letters[j].len == w.len) &&
            ((memcmp(w.word, letters[j].word, w.len) == 0)))
        {
          ret = false;
          break;
        }
      }

      // New one
      *pre = w;
    }

    if (!ret)
    {
      break;
    }

    pw += w.len + 1; // Add one for space
  }

  // If true --> Check if s contains any other words
  if (ret)
  {
    int s_len = strlen(s);

    if ((pw - 1 - s) != s_len)
    {
      ret = false;
    }
  }

  return ret;
}

// @lc code=end

