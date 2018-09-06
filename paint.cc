#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

/*
  Comment the following line when running in HackerRank.
  Otherwise read the input from a file 'paint.data'.
*/
#define DEBUG 1

using namespace std;
struct Dot {
  int row;
  int col;
  int darkness;
};

typedef struct Dot st_dot;


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
