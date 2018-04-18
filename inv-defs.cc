/*
 * NAME: inv-defs.cpp -- counting inversions in a permutation
 * SYNOPSIS: to compile 'g++ inv-defs.cpp' in Multilab,
             to execute './a.out < in.txt'
             where in.txt is a permutation -- n+1 lines,
             n followed by n lines of the sequence elements
 * DESCRIPTION: Calculates the total mumber of inversions in a permutatation 
             based directly on the definition of an inversion: the number of pairs a[i] > a[j] for i < j.
 * AUTHOR: Paul Barrett 
 * ALGORITHM: comparing all pairs of elements in the input sequence
   to see if they are inverted.
 * RUNNING TIME: O(nlog(n)) time
 * SPACE: O(n)
*/

#include <iostream>
#include <math.h>
#include <vector> //for vectors
#include <algorithm> //for transform
using namespace std;
#define SIZE 100001

//function required for transform for dividing entire vector by 2
int divideBy2(int k)
{
	return k/2;
}

int main()
{

	vector<long int> a; // permutation/sequence
	unsigned int n,temp; 

//INPUT (from standard input, can use Unix input redirection '<')
	cin >> n; //read in the length of the sequence
	for (int i = 0; i < n; i++)
	{
		cin >> temp; // read in n numbers of the sequence
		a.push_back(temp); //push numbers onto vector a
	}

//COUNTING INVERSIONS -- THIS PART CAN BE REPLACED WITH WR
	
	vector<int> cVect(n+1, 0); //count vector
	vector<long int> zeroVector(n, 0); //vector of zeros
	long int countInversions = 0; //counter for number of inversions
	while(a != zeroVector)
	{
		
		for(int j = 0; j < n; j++)
		{
			cVect[a[j]]++;	//count how many times each number is passed
		
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

//OUTPUT
	cout << endl << "Output: \n" << countInversions << endl;	

	return 0;

}
