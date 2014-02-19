// Filename: TextDemo.cpp
// Date Created: 01/09/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"
#include "TextLL.h"
#include <string>
using namespace std;
using lance_project::TextLL;

int main() {
	// Instantiates the TextLL objects
	TextLL text1 = TextLL("testfile1.txt");
	TextLL text2 = TextLL("testfile2.txt");
	TextLL text3 = TextLL("testfile2.txt");
	
	// Displays the contents of the two TextLL Objects.
	cout << endl << "#2) The TextLL instances: " << endl;
	cout << "Text1 = " << text1 << endl;
	cout << "Size = " << text1.size() << endl << endl;
	cout << "Text2 = " << text2 << endl;
	cout << "Size = " << text2.size() << endl << endl;
	
	// Adds the contents of text2 to text1
	text1 += text2;
	cout << endl << "#3) Add contents of text2 to text1: " << endl;
	cout << "Text1 = " << text1 << endl;
	cout << "Size = " << text1.size() << endl << endl;
	
	// Removes all occurences of testfile3 from text1.
	text1 -= text3;
	cout << endl << "#4) Remove all occurrences of testfile3 from text1: " << endl;
	cout << "Text1 = " << text1 << endl;
	cout << "Size = " << text1.size() << endl << endl;
	cout << "Text3 = " << text3 << endl;
	cout << "Size = " << text3.size() << endl << endl;
	
	// Queries the user for a string value and adds it to text2
	cout << endl << "#5) Query user for string value and add to test2: " << endl;
	string addvalue;
	getline(cin, addvalue);
	text2.add(addvalue);
	
	// Displays text 2
	cout << endl << "#6) Text2 = " << text2 << endl;
	cout << "Size = " << text2.size() << endl << endl;
	
	// Queries the user for a string value and displays how many times it occurs in text1
	cout << endl << "#7) Query user for string value and display how many times it occurs in text1: " << endl;
	string search;
	cin >> search;
	cout << "It occurs " << text1.count(search) << " times" << endl;	
	return 0;
}
