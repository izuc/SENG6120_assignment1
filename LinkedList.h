// Filename: LinkedList.h
// Date Created: 01/09/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_LINKEDLIST_H
#define LANCE_LINKEDLIST_H
namespace lance_project {
	class LinkedList {
		public:
			// The default constructor for the LinkedList.
			LinkedList();
			
			// The destructor for the LinkedList. 
			// Clears the List nodes, and deletes the head & tail pointers.
			~LinkedList();
			
			// Adds a new Node to the end of the LinkedList.
			void addLast(Node::value_type value);
			
			// Adds a new Node to the beginning of the LinkedList.
			void addFirst(Node::value_type value);
			
			// Adds a new Node after the prev_node.
			void insert(Node* prev_node, Node::value_type value);
			
			// Chops the head off the LinkedList.
			void removeHead();
			
			// Removes the Node after the prev_node.
			void remove(Node* prev_node);
			
			// Clears the LinkedList.
			void clear();
			
			// Clears & then performs a deep copy of the Nodes
			// linked after the source_ptr adding them to the end
			// of the current instance.
			void copy(Node* source_ptr);
			
			// Retrieves the Node matching the received target value.
			Node* search(Node::value_type target);
			
			// Fetches the Node at that present position in the LinkedList.
			Node* getNode(int position);
			
			// Fetches the head Node of the LinkedList.
			Node* getHead();
			
			// Determines & returns the size of the LinkedList.
			int size();
		private:
			Node* head_ptr; // Pointer to the head Node.
			Node* tail_ptr; // Pointer to the tail Node.
	};
}
#endif
