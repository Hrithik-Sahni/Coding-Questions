#include<iostream>
using namespace std;

class Node{
	int data;
	Node * next;

	public:

		Node(int data)
		{
			this -> data = data;
			next = NULL;
		}
}
int main()
{
	//Static 
	Node n1(1);

	Node n2(2);

	n1.next = &n2;
	return 0;
}