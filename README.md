Yodaness Problem
http://www.spoj.com/problems/YODANESS/

-- pa1c-sample.cpp: Show # of inversions or "Yodaness Level"
-- inv-devs.cpp: create WR algorithm to count number of inversions for given permutation in O(nlogn). Implemented in pa1c-sample for full yodaness problem
-- testgen.cpp: a simple program I created for making test cases.
-- sample input files: input1000.txt, etc. Used to test different permutations

To compile:
g++ -std=c++11 pa1c-sample.cpp -o yodaness

To run:
$ ./yodaness < [sample input file]
