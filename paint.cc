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


// Predicate: return true if cell at (row, col) is a dot.
// Complexity: Worse case O(n_dots)
bool is_a_dot(int row, int col, const vector<st_dot> &dots)
{
  return any_of(dots.begin(),
                dots.end(),
                [&row, &col](const st_dot &dot)
                { return row == dot.row && col == dot.col; });
}

// Return the dot at cell (row, col)
// Complexity: Worse case O(n_dots)
const st_dot &dot_at(int row, int col, const vector<st_dot> &dots)
{
  for (auto &dot : dots)
    if (row == dot.row && col == dot.col)
      return dot;
}


// Return minimum path from DOT to the cell at (row, col)
// I assume the minimum distance is: just adding the
// difference on cols/rows.
// Complexity: Constant time.
int min_path(int row, int col, const st_dot &dot)
{
  return abs(dot.row - row) + abs(dot.col - col);
}

// Maximum ink value: check all dots
// Complexity: O(n_dots).
int max_ink_value(int row, int col, const vector<st_dot> &dots)
{
  vector<int> ink_values;
  // Complexity: O(n_dots)
  for (const auto &dot : dots) {
    int value = dot.darkness - min_path(row, col, dot);
    if (value < 0) value = 0;
    ink_values.push_back(value);
  }
  return *max_element(ink_values.begin(), ink_values.end()); // O(n_dots)
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
    // Complexity: O( height*width ) * O( n_dots )
    // First part from the 2 loops; the second is the complexity of
    // `max_ink_value'.
    for (int row=0;row<height;++row) {
      for (int col=0;col<width;++col) {
        result += max_ink_value(row, col, dots);
      }
    }
    cout << result << endl;
  }

  
#ifdef DEBUG
  INFILE.close();
#endif  
  return 0;
}
