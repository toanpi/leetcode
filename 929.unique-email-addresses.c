/*
 * @lc app=leetcode id=929 lang=c
 *
 * [929] Unique Email Addresses
 */

// @lc code=start

int numUniqueEmails(char **emails, int emailsSize)
{
  char list[emailsSize][100];
  int count = 0;

  memset(list, 0, sizeof(list));

  for (int i = 0; i < emailsSize; i++)
  {
    char *e = emails[i];
    bool ignored = false;
    char str[100] = {0};
    int idx = 0;

    // Local name
    while ((*e) != '@')
    {
      if (ignored)
      {
        
      }
      else if ((*e) == '+')
      {
        ignored = true;
      }
      else if ((*e) != '.')
      {
        str[idx++] = *e;
      }

      e++;
    }

    // @
    str[idx++] = *e;
    // Domain
    e++;
    strcpy(&str[idx], e);

    bool found = false;

    for (int j = 0; j < count; j++)
    {
      if (strcmp(list[j], str) == 0)
      {
        found = true;
        break;
      }
    }

    if (!found)
    {
      strcpy(list[count++], str);
    }
  }

  return count;
}

// @lc code=end
