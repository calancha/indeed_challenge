# HackerRank Indeed.com Paint Problem

You are a painter and you have a M x N (rows x columns) grid.<br/>
In R of the cells you have dropped a paint drop.<br/>
Each drop has its own darkness D.<br/>
Every darkness is an integer
```0 < D <= 255```

The paint propagates to neighbor cells in the following way:

1. If the current cell has darkness d, the neighour cells get
   darkness d-1; second neighbours d-2; ...; d-1 neighours
   get d-(d-1) = 1 darkness.

2. If one cell, CELL, might get paint from 2 different neighbours,
   the final CELL darkness is the maximum of the 2 possible darkness.

# Output
Print to the standard output:

The sum of the darkess values for all the cells in the final configuration.
Here final configuration means once all drops have leaked to their neighbours.

# Input
You will receive from the standard input:
1. An integer, the number of tests.
2. 2 integers, H and W, the height and width of the grid.
3. An integer, R, the number of cells with a paint drop.
4. The following are R lines containing 3 numbers:
   row, column and darkness of that drop; i.e., the position
   of the drop and its darkness value.

You must read the input from the standard input and write your output
to the standard output.

# Example
For the following input:
```
1
3 4
2
0 0 255
1 2 255
```
You should print out to the standard output:
```
3046
```

# Explation
This is the initial configuration:
```
255   .     .      .

.     .     255    .

.     .     .      .
```

The final configuration is as follows:
```
255 254 254 253

254 254 255 254

253 253 254 253
```

# A C++ implementation

Following is a C++ (possible) solution to this problem.  I say possible
because I have no longer access to the problem test suite.
AFAICT, it works on my coustom small tests.

To run in HackerRank site, comment out the line:

```#define DEBUG 1```

Uncomment it to run the code locally.  In this case, you need to
supply the input in a file 'paint.data' (under same directory).
