//------------------------------------------------------------------------------
// 2. [10 marks]
//
// Implement a function reverseAfter() to reverse the elements in a linked list
// from the first occurrence of a given value.
// e.g. given the input A B C D E F and the value D return the list A B C F E D
// You should do this inplace without creating new nodes.
// Assume the list is null terminated.

struct Node
{
	struct Node* next;
	int val;
};

void reverseAfter( struct Node* head, int val );