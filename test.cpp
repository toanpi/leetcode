#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cpp_h.h"

#include "build_binary_tree.c"
// struct  TreeNode *a = build((int []){1,NULL_NODE,1,0,1,0,1}, 7);

#define AS(arr)  (sizeof((arr))/sizeof((arr)[0]))

// #include ""
#include "81.search-in-rotated-sorted-array-ii.cpp"


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

  vector<int> v = {4,5,6,7,0,1,2};

  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

  sol.search(v, 5);

  return 0;
}
