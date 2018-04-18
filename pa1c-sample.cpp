/*
 * NAME: pa1c-sample.cpp -- reading input for Yodi problem
 * SYNOPSIS: to compile 'g++ -std=c++11 pa1c-sample.cpp' in Multilab,
       Note: We use C++11 here, specifically "auto" and range-based for loops.
       Therefore you must pass g++ the command-line option "-std=c++11".
             to execute './a.out < in101s.txt'
             where in101s.txt an input instance for the Yodi problem -- see
		the specs for Yodi
 * DESCRIPTION: Reading part for  the Yodi problem.
		This sample just reads and process
		the input file for Yodi problem.
		TODO: counting the distance (# inversions) between
		the Yodi and English sentences.
 * AUTHOR: Paul Barrett
 * ALGORITHM: TODO: Count the number of inversions: first line sequence versus
		the second line sequence (permutation)
 * RUNNING TIME: O(n log n) with WR algorithm
 * SPACE: O(n)
*/

#include <iostream> // cin etc; streamsize
#include <sstream>  // istringstream
#include <limits>   // numeric_limits
#include <map>      // map
#include <string>   // string; getline
#include <vector> //for vectors
#include <algorithm> //for transform
#include <math.h>
using namespace std;
#define SIZE 100001

//function required for transform for dividing entire vector by 2
int divideBy2(int k)
{
        return k/2;
}

int wrAlg(vector<int> inVect)
{
	vector<int> a = inVect; // permutation/sequence
        unsigned int n = a.size();

	//COUNTING INVERSIONS
        vector<int> cVect(n+1, 0); //count vector
        vector<int> zeroVector(n, 0); //vector of zeros
        int countInversions = 0; //counter for number of inversions
        while(a != zeroVector)
        {

                for(int j = 0; j < n; j++)
                {
                        cVect[a[j]]++;  //count how many times each number is passed

                        //if a[j] is even, add to countInversions the number stored in cVect[a[j]+1]
                        if(a[j]%2 == 0)
                        {
                                countInversions += cVect[a[j]+1];
                        }
                }

                //divide vector a by 2
                transform(a.begin(), a.end(), a.begin(), divideBy2);

                //set cVect back to zero for next pass
                for(int i = 0; i < n+1; i++)
                {
                        cVect[i]=0;
                }
        }
	cout << "Output = " << countInversions  << endl;
}

// Helper function: Parse a string into space-delimited words and return a map
// from the word to the index (word count) of its first occurrence.  So, for
// example, index_words("this is a test") would return a map with the following
// key-value pairs:
//    "a"    -> 2
//    "is"   -> 1
//    "test" -> 3
//    "this" -> 0
map<string, int> index_words(const string &line)
{
	// The map we are going to return
	map<string, int> result;

	// istringstream allows us to read from a string as though it were an
	// input stream.  That way we can use operator>> to do the parsing,
	// rather than trying to find the whitespace and extract substrings "by
	// hand".
	istringstream in(line);

	string word; // The word we are extracting from the string.
	int index = 0;    // The index in the string: 0 for the first word, etc.

	// operator>> returns (a reference to) the stream "in" itself.  When
	// converted to a bool, that evaluates to true if the stream is still
	// good, and false if there was an error or we reached the end of file.
	while (in >> word)
	{
		// Don't insert the word or increment the index if this word
		// is a repeat  That doesn't actually matter for this problem,
		// because we are guaranteed that the words are unique, but it's
		// something to consider.
		if (result.find(word) == result.end())
		{	
			result[word] = index++;	
		}
	}
	return result;
}

int main()
{
	// Number of problem instances
	int instances;
	cin >> instances;

	for (int i = 0; i < instances; ++i)
	{
		// Number of words in each line; not actually used, since
		// index_words handles an arbitrary number of words.
		int numwords;
		cin >> numwords;

		// Skip characters up to and including the next newline.  It is
		// necessary to do this, or something similar, when switching
		// from operator>> to getline(), since >> does not remove the
		// trailing newline.  If this call were omitted, the first
		// getline would return an empty string (the "rest" of the
		// numwords line).
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// The lines as Yoda says them and as speaker of standard English
		// would say them.
		string yoda_line, english_line;

		getline(cin, yoda_line);
		getline(cin, english_line);

		// Maps from the words on each line to their word positions.
		// Using "auto" so that we don't have to type std::map<blah blah>
		// yet again.
		auto yoda_idx = index_words(yoda_line);
		auto english_idx = index_words(english_line);

		// TODO: now count the number of pairs of words that changed their
		// order.
		vector<int> yodavec;	//store yoda vector
		vector<int> engvec;	//store english vector
		vector<int> diffvec;	//difference vector
		map<string, int> :: iterator itr;	//map iterator
		//STORING YODA AND ENGLISH VECTORS
		for(itr = yoda_idx.begin(); itr != yoda_idx.end(); itr++)
		{
			yodavec.push_back(itr->second);
		}
		for(itr = english_idx.begin(); itr != english_idx.end(); itr++)
                {
                        engvec.push_back(itr->second);
                }
		//COMPUTE DIFFERENCE VECTOR
		//Yoda   : 3 1 5 0 2 4 (or i will help you not)
		//English: 4 1 3 0 2 5 (or i will not help you)
		//Starting from 0, check that 0 index in both match.
		//If they match, put onto vector and look for index for 1 in english and compare to Yoda
		//Continue to check. Up till 2 they match. If they differ (Y3:E4 at index 0), choose the yoda value for 
		//that english index. English index 4 does not match 3 in Yoda. So differencevector[4] = 3, etc.
		//Difference: 0 1 2 5 3 4
		for(int i = 0; i < numwords; i++)
		{
			for(int j = 0; j < engvec.size(); j++)
			{
				if(engvec[j] == i)
					if(yodavec[j] != i)
					{
						diffvec.push_back(yodavec[j]);				
					} else {
						diffvec.push_back(engvec[j]);
					}
			}
		}
		//use the WR algorithm on the difference vector to find Yodaness level
		wrAlg(diffvec);
	}
}
