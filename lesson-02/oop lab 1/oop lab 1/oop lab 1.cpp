// oop lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Student {
public:
	int index;
	string major;
};
class Desk {
public:
	int height;
	string material;
};
int main(int argc, const char *argv[])
{
	Student PUTstudent;
	PUTstudent.major = "bioinformatics";
	PUTstudent.index = 155615;
	cout << PUTstudent.major << endl;
	cout << PUTstudent.index << endl;
	Desk Mydesk;
	Mydesk.height = 100;
	Mydesk.material = "wood";
	cout << Mydesk.height << endl;
	cout << Mydesk.material << endl;
	return 0;
}

