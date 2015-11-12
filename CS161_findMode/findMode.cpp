/*********************************************************************
** Author: Giovanni Rosati
** Date: 2015-11-10
** Description: A function with two parameters:
	1) an array of ints
	2) the size of the array
	that returns a vector containing the mode(s) of the array.
	If the array has multiple values with the same occurance it
	returns each of those values.

*********************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> findMode(int arrayIn[], int arrayLength)
{
	sort(arrayIn, arrayIn + arrayLength); //sort the array

	int count = 1;
	int max = 1;
	int mode = arrayIn[0];
	for (int i = 0; i < arrayLength; i++)
	{
		if (arrayIn[i] == arrayIn[i + 1])
		{
			count++;
			if (count > max)
			{
				max = count;    //set max equal to the occurances of the mode value
				mode = arrayIn[i];
			}
		}
		else
			count = 1;
	}

	// Because the array was sorted in ascending order, the
	// position of the "lowest valued" Mode has now been determined

	// used for testing
	//cout << "First found Mode value: " << mode << endl;
	//cout << "Number of times the mode value occurs: " << max << endl;
	//system("pause");

	//repeat the algorithm, pushing each value with the same occurance count into a vector
	vector<int>results;

	if (max == 1)  	//handler for the case when each value in the array occurs only once
		for (int i = 0; i < arrayLength; i++)
		{
			results.push_back(arrayIn[i]);
		}
	else  //handler for all other cases
	{
		for (int i = 0; i < arrayLength; i++)
		{
			if (arrayIn[i] == arrayIn[i + 1])
			{
				count++;
				if (count == max)
				{
					results.push_back(arrayIn[i]);
				}
			}
			else
				count = 1;  //reset the counter once the value at the current position is not equal to the next value
		}
	}

	//test section to see the contents of the vector
	//cout << "Contents of vector to be returned: " << endl;
	//for (int v = 0; v < results.size(); v++)
	//{
	//	cout << results[v] << " ";
	//}
	//cout << endl;
	//system("pause");  //used when testing in Visual Studio

	return results;
}

//main for testing
//int main()
//{
//	vector<int>results;
//
//	int arrayIn[] = { 7, 5, 7, 6, 5, 6, 3, 2, 1, 0 };  //test array 1
//	//int arrayIn[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };  //test array 2
//	//int arrayIn[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };  //test array 3
//
//	int arrayLentgh = 10;
//
//	results = findMode(arrayIn, arrayLentgh);
//
//	cout << "Contents of vector returned to main: " << endl;  //test output of the vector
//	for (int v = 0; v < results.size(); v++)
//	{
//		cout << results[v] << " ";
//	}
//	//system("pause");  //used when testing in Visual Studio
//
//	return 0;
//}