//Second cleaner version of Linked List
#include <iostream>
using namespace std;

class LinkedList
{
	private:
		struct Node
		{
			int number;
			Node* next;
		};
		Node* head;
	
	public:
	LinkedList()
	{head = NULL;}
	
	bool addNode(int num)
	{
		Node* tracker;
		Node* previous;
		Node* newNode = new Node;
		newNode->number = num;
	
		//Empty List
		if(head == NULL)
		{
			head = newNode;
			newNode->next = NULL;
			return true;
		}
		
		//Non-Empty List
		else
		{
			tracker = head;
			previous = NULL;
			while(tracker-> next)
			{
				if(tracker->number > num)	//Put the number here
				{
					if(previous == NULL)	//if first node
					{
						newNode->next = head;
						head = newNode;
						return true;
					}
					else		//NEither first or last
					{
						previous->next = newNode;
						newNode->next = tracker;
						return true;
					}
				}
				else //Move to check next node
				{
					previous = tracker;
					tracker = tracker->next;
				}
			}
			//At end of list, add and make next = NULL ( nulptr if c++11 )
			tracker->next = newNode;
			newNode->next = NULL;
			return true;
		}
		return false;
	}
	
	bool findNode(int num)
	{
		Node* tracker = head;
		while(tracker->next)
		{
			//Check each node for number and return true if found
			if(tracker->number == num)
			{
				return true;
			}
		tracker = tracker->next;
		}
		//Check last number in list
		if(tracker->number == num)
		{
			return true;
		}
		//Not found return false
		return false;
	}
	
	void displayList()0
	{
		if(head == NULL)
			cout<<"This list is empty"<<endl;
		else
		{
			int count = 0;
			Node* tracker = head;
			cout<<"-----------------------------------------"<<endl;
			while(tracker->next)
			{
				cout<<"Node "<<count<<" | Data "<<tracker->number<<endl;
				tracker = tracker->next;
				count++;
			}
			// For the last node in the list
			cout<<"Node "<<count<<" | Data "<<tracker->number<<endl;
			cout<<"-----------------------------------------"<<endl;
		}
	}

};


int main()
{
	LinkedList list;
	int checknum;
	for(int i = 0 ; i<100 ;i++)
	{
		list.addNode(i);
	}
	list.displayList();
	cout<<"Enter a number to check the list for > ";
	cin>>checknum;
	if(list.findNode(checknum))
		cout<<checknum<< " was found in the list\n";
	else
		cout<<checknum<<" was not found in the list\n";
	return 0;
}
