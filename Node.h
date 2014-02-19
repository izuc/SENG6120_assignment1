// Filename: Node.h
// Date Created: 01/09/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_NODE_H
#define LANCE_NODE_H
#include <string>
using namespace std;
namespace lance_project {
	class Node {
		public:
			// A public datatype defined in order to make the LinkedList
			// have more reusability. Allowing the alteration of the datatype
			// to be centralised.
			typedef string value_type;
			
			// The default constructor creates a empty instance.
			Node();
			
			// The constructor creates a instance with data.
			Node(const value_type& data_field);
			
			// The constructor creates a instance with data and a Node link.
			Node(const value_type& data_field, Node* link_field);
			
			// The destructor ensures that the memory is freed.
			~Node();
			
			// The setter for the data.
			void setData(const value_type& data_field);
			
			// The setter for the next linked Node.
			void setLink(Node* link_field);
			
			// The getter for the data.
			value_type data() const;
			
			// The getter for the next linked Node.
			const Node* link() const;
			
			// The getter for the next linked Node.
			Node* link();
		private:
			value_type data_field; // Instance field containing the data.
			Node* link_field; // Pointer to the next Node.
	};
}
#endif
