#include <fstream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/*
  Comment the following line when running in HackerRank.
  Otherwise read the input from a file 'anagram.data'.
*/
#define DEBUG 1

using namespace std;
struct Dot {
  int row;
  int col;
  int darkness;
};

typedef struct Dot st_dot;

// Predicate: return true if dot is a neighbour for the cell at (row, col)
bool is_a_neighbour(int row, int col, const st_dot &dot)
{
  if (row == (dot.row - 1) && col == dot.col) return true; // up
  if (row == (dot.row + 1) && col == dot.col) return true; // down
  if (row == dot.row && col == (dot.col - 1)) return true; // left
  if (row == dot.row && col == (dot.col + 1)) return true; // right
  return false;
}

// Check if cell(row, col) has any dot neighbour
// Worse case: O(n_duts)
bool has_dot_neighbour(int row, int col, vector<st_dot> &dots)
{
  return any_of(dots.begin(),
                dots.end(),
                [&row, &col](const st_dot &dot) { return is_a_neighbour(row, col, dot); });
}



// Return referece to dot neighbour with maximum darkness
st_dot &max_dot_neighbour(int row, int col, vector<st_dot> &dots)
{
  return dots.front(); // TODO IMPLEMENT IT  
}

// Predicate: return true if cell at (row, col) is a dot.
bool is_a_dot(int row, int col, vector<st_dot> &dots)
{
  return any_of(dots.begin(),
                dots.end(),
                [&row, &col](const st_dot &dot) { return row == dot.row && col == dot.col; });
}

// Return the dot at cell (row, col)
st_dot &dot_at(int row, int col, vector<st_dot> &dots)
{
  for (auto &dot : dots)
    if (row == dot.row && col == dot.col)
      return dot;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
#ifdef DEBUG 
  ifstream inFile; 
  inFile.open("paint.data");
#define INFILE inFile
#else
#define INFILE cin
#endif  
  int n;
  INFILE >> n;
  while (n--) {
    int height, width, n_dots;
    INFILE >> height >> width;
    INFILE >> n_dots;
    // printf("%d %d %d\n", height, width, n_dots);
    vector<st_dot> dots;
    while (n_dots--) {
      st_dot dot;
      INFILE >> dot.row >> dot.col >> dot.darkness;
      dots.push_back(dot);
    }
    int result = 0;
    for (int row=0;row<height;++row) {
      for (int col=0;col<width;++col) {
        if (is_a_dot(row, col, dots)) {
          result += dot_at(row, col, dots).darkness;
        } else if (has_dot_neighbour(row, col, dots)) {
          st_dot max_dot = max_dot_neighbour(row, col, dots);
          result += (max_dot.darkness - 1);
        }
      }
    }
    cout << result << endl;
  }

  
#ifdef DEBUG
  INFILE.close();
#endif  
  return 0;
}
