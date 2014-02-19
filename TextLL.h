// Filename: TextLL.h
// Date Created: 01/09/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_TEXTLL_H
#define LANCE_TEXTLL_H
#include <string>

using namespace std;
namespace lance_project {
	class TextLL {
		public:
			// Creates an instance that does not contain any text data.
			TextLL();
			// Creates an instance and stores the file’s content in the instance.
			TextLL(string fileName);
			// Returns a count of the number of words in the TextLL.
			int size();
			// Appends a string to the TextLL instance.
			void add(string value);
			// Returns the number of occurrences of value in the TextLL.
			int count(string value);
			
			// Loads the file contents into the internal datastructure.
			void loadFile(string fileName);
			
			// Fetches a pointer to the list.
			LinkedList* getList();
			
			// Overloaded concatenation operator (i.e. ‘+=’). The result of use of this
			// operator is that the TextLL arguments are concatenated and the answer is
			// stored in the left argument.
			TextLL operator+=(TextLL & rhs);
			
			// Overloaded assignment operator (i.e. ‘-=’). The result of use of this
			// operator is that all occurrences of the RHS argument are removed from the
			// LHS argument and the answer is stored in the left argument.
			TextLL operator-=(TextLL & rhs);
		private:
			LinkedList* list;
	};
	
	// Overloaded output operator (i.e. ‘<<’) that outputs the content of the TextLL
	// in a form suitable for printing by the cout statement.
	ostream & operator<<(ostream & out, TextLL & value);
	static const string OUTPUT_DIVIDER = " ";
}
#endif
