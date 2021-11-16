#include "zadatak01.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void zadatak01::VectorInput(vector<int>& v, int el)
{
	int n;
	cout << "enter the elements of the array: " << endl;
	for (int i = 0; i < el; i++)
	{
		cin >> n;
		v.push_back(n);
	}
}
void zadatak01::VectorInputLimits(vector<int>& v1, int a, int b)
{
	cout << "enter the elements of the array: " << endl;
	int n;
	for (;;)
	{
		cin >> n;
		if (n >= a && n <= b)
		{
			v1.push_back(n);
		}
		else
			break;
	}
}
void zadatak01::VectorOutput(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

