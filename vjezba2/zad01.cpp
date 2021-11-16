#include "zadatak01.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	zadatak01 vec;
	vector<int> v;
	vector<int> v1;
	int el;
	int a;
	int b;
	cout << "enter the number of members: " << endl;
	cin >> el;
	vec.VectorInput(v, el);
	vec.VectorOutput(v);
	cout << endl;
	cout << "enter the size limits of the members [a,b]: " << endl;
	cin >> a >> b;
	vec.VectorInputLimits(v1, a, b);
	vec.VectorOutput(v1);
	return 0;
}


