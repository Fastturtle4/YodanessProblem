#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	vector<int> nums;
	cin >> n;
	cout << "1\n" << n << endl;
	srand (time(NULL));
	for(int i = 0; i < n; i++)
	{
		nums.push_back(i);		
	}
	random_shuffle(nums.begin(), nums.end());
	for(int i = 0; i < n; i++)
        {
                cout << "abcd" << nums[i] << " ";
        }

	cout << endl;
	for(int j = 0; j < n; j++)
        {
                cout << "abcd" << j << " ";
        }
	cout << endl;
	return 0;
}
