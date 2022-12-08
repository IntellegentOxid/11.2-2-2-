#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const unsigned int ARRSIZE = 200;
const int ABSLIMIT = 50;

int rrand(int range_min, int range_max);

int main()
{
	int arr[ARRSIZE];
	srand(time(NULL));
	for (int i = 0; i < ARRSIZE; i++)
	{
		arr[i] = rrand(-ABSLIMIT, ABSLIMIT);
	}

	cout << "\nGenerated array: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	unsigned int length[ARRSIZE], index[ARRSIZE], counter = 0, prev = 0;
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (arr[prev] < arr[i])
			counter++;
		else
			counter = 0;

		length[i] = counter;
		index[i] = prev;

		prev = i;
	}

	for (int i = 0; i < ARRSIZE; i++)
	{
		if (length[i] != 0)
		{
			cout << "The length of continuous sequence of increasing numbers: " << length[i];
			cout << "\nIts initial index: " << index[i] << endl;
		}
	}
}

int rrand(int range_min, int range_max)
{
	return rand() % (range_max - range_min + 1) + range_min;
}