
#include "cpp_h.h"

#include "build_binary_tree.c"
// struct  TreeNode *a = build((int []){1,NULL_NODE,1,0,1,0,1}, 7);

#define AS(arr)  (sizeof((arr))/sizeof((arr)[0]))

// #include "object_Oriented_Graph.cpp"

// #include ""
#include "969.pancake-sorting.cpp"


Solution sol;

int main(void)
{
  // char b[] = "1011";
  // int arr[] = {};
  int arr[] = {-1,0,1,2,-1,-4};
  int size = 0;
  // int arr[] = {10,9,8,7,6,5,4,3,2,1};
  // int tree[] = {5, 3, 6, 2, 4, NULL_NODE, 8, 1, NULL_NODE, NULL_NODE, NULL_NODE, 7, 9};
  int tree[] = {2, 2,2};
  struct TreeNode *a = build(tree, sizeof(tree) / sizeof(int));

  vector<int> v = {3, 2, 4, 1};
  vector<char> c = {'A','A','A','B','B','B'};

  vector<vector<int>> matrix = {{0,2},{1,3},{2,4},{3,5},{4,6}};
  vector<vector<char>> matrixC = {{'1','1','0','1'},{'1','1','0','1'},{'1','1','1','1'}};
  string s = "2611055971756562";
  vector<vector<string>> accounts =
  {{"David","David0@m.co","David1@m.co"},
   {"David","David2@m.co","David3@m.co"},
   {"David","David3@m.co","David4@m.co"},
   {"David","David4@m.co","David5@m.co"},
   {"David","David1@m.co","David2@m.co"}};
  // {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
  //  {"John", "johnsmith@mail.com", "john00@mail.com"},
  //  {"Mary", "mary@mail.com"},
  //  {"John", "johnnybravo@mail.com"}};
    
  sol.pancakeSort(v);

  return 0;
}
