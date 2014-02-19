// Filename: TextLL.cpp
// Date Created: 01/09/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>

#include "Node.h"
#include "LinkedList.h"
#include "TextLL.h"
#include <fstream>
#include <string>

using namespace std;
using lance_project::Node;
using lance_project::LinkedList;
using lance_project::TextLL;

namespace lance_project {
	TextLL::TextLL() {
		this->list = new LinkedList();
	}

	TextLL::TextLL(string fileName) {
		this->list = new LinkedList();
		this->loadFile(fileName);
	}

	int TextLL::size() {
		return this->list->size();
	}
	
	void TextLL::add(string value) {
		string token; // Used to store a completed token.
		// Iterates throughout the received value characters.
		for(unsigned i = 0; i < value.size(); i++) {
			// If the character is not a space.
			if (!isspace(value[i])) {
				token += value[i]; // It will be added to the token.
			} else {
				// If a space was found it adds the previous token to the list.
				this->list->addLast(token.c_str());
				token.clear(); // Clears to start new token.
			}
		}
		// If the token has a value.
		if (!token.empty()) {
			// It is added to the list.
			this->list->addLast(token.c_str());
		}
	}
	
	int TextLL::count(string value) {
		int count = 0;
		for (const Node* current = this->list->getHead(); current != NULL; 
									current = current->link()) {
			if (current->data() == value) {
				count++;
			}
		}
		return count;
	}
	
	void TextLL::loadFile(string fileName) {
		char c; // The current character being read.
		ifstream is; // The input stream for the file.
		is.open(fileName.c_str()); // Opens the file (passing the received fileName).
		string token; // Declares token.
		while(is.good()) { // While there is data.
			c = is.get(); // It will get the next char.
			if (is.good()) { // Checks to make sure its not the EOF character.
				if (!isspace(c)) { // If the char is not a space.
					token += c; // It will add it to the token.
				} else {
					// Once a space is found, it will add the token to the list.
					this->list->addLast(token.c_str());
					token.clear(); // Clears to start new token.
				}
			}
		}
		// If the token has a value.
		if (!token.empty()) {
			// It is added to the list.
			this->list->addLast(token.c_str());
		}
		is.close();	// Closes input stream.
	}
	
	LinkedList* TextLL::getList() {
		return this->list;
	}
	
	// The += operator is used to append the contents of the right hand side
	// TextLL to the left. It is used for example in a statement like TextLL1 += TextLL2.
	// It enables for the TextLL tokens to be simply appended together.
	TextLL TextLL::operator+=(TextLL & rhs) {
		// Iterates foreach node in the (right hand side) TextLL.
		for (const Node* current = rhs.getList()->getHead(); current != NULL; 
									current = current->link()) {
			// Adds the node data to the Last position of the LinkedList.
			this->list->addLast(current->data());				
		}
		// Returns the pointer to the current TextLL instance.
		return *this;
	}
	
	TextLL TextLL::operator-=(TextLL & rhs) {
		// Iterates foreach node in the (right hand side) TextLL.
		// Which are the tokens that need to be removed.
		for (const Node* current = rhs.getList()->getHead(); current != NULL; 
									current = current->link()) {
			
			// Iterates throughout the LHS list, when the node data matches
			// the current data it will remove the node.
			Node* node = this->list->getHead(); // Sets the starting node with the head.
			Node* prev; // Declares previous node.
			while(node != NULL) { // Iterates until the node is NULL.
				// If the node data matches the current data.
				if (node->data() == current->data()) {
					// If the node is the head.
					if (this->list->getHead() == node) {
						// It will then remove the head.
						this->list->removeHead();
					} else {
						// Otherwise it will remove the previous.
						this->list->remove(prev);
					}
				}
				prev = node; // Sets the previous to the node.
				node = node->link(); // Sets the node to the next.
			}
		}
		return *this; // Returns the pointer to the current TextLL instance.
	}
	
	// The << operator is used to output the contents of each token
	// in the TextLL. It iterates throughout each Node in the LinkedList,
	// whilst appending the output and separating each element with a divider.
	ostream & operator<<(ostream & out, TextLL & value) {
		//LinkedList* list = value.getList();
		for (const Node* current = value.getList()->getHead(); current != NULL; 
									current = current->link()) {
			// Appends the data, separating each element with a divider.
			out << current->data() << OUTPUT_DIVIDER;
		}
		return out; // Returns the output stream.
	}
}
