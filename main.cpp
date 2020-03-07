#include <iostream>
#include "binary_tree.hpp"

using namespace std;


int main()
{
	binary_tree<char*> tr;

	tr.push((char*)"abc");
	tr.push((char*)"abcd");
	tr.push((char*)"ac");
	tr.push((char*)"hello");

	/*tr.push(1);
	tr.push(1234231);
	tr.push(-100);
	tr.push(2);
	tr.push(10);
	tr.push(5);
	tr.push(-110);
	tr.push(0);
	tr.push(100);
	tr.push(100);*/


	char* elem = (char*)"abc";
	if (tr.find(elem))
		cout << "Element '" << elem << "' exist inside this tree" << endl;
	else
		cout << "Didn't find element " << elem << endl;
	tr.print();
	return 0;
}