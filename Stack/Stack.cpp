#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


class Stack
{
private:
  struct Node
  {
    int data;
    Node* next;
  };
  Node* head;
  int len;

public:
  Stack()
  {head = NULL; len = 0;}

  int length()
  {return len;}
  void displayStack()
  {
    if(!head)
    {
      cout<<"Stack is empty"<<endl;
      return;
    }
    else
    {
      Node* tracker = head;
      cout<<"|";
      while(tracker->next)
      {
        cout<<setw(3)<<tracker->data<<"|";
        tracker = tracker->next;
      }
      cout<<setw(3)<<tracker->data<<"|\n";
      return;
    }
  }

  bool push(int num)
  {
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    len++;
    return true;
  }

  int pop()
  {
    if(head)
    {
      int returnData = head->data;
      Node* tmp = head->next;  // grab the second node
      delete head;
      head = tmp;
      len--;
      return returnData;
    }
    else
    {
      cout<<"This list is empty\nDon't do whatever you just did\n";
      return -1; //this is not a good way to handle this.  at all.
    }
  }
};

int main()
{
  Stack test;
  int tmp;
  for(int i = 0 ; i<10 ; i++)
  {
    tmp = (i * rand())%100;
    test.push(tmp);
    cout<<"adding   "<<setw(3)<<tmp<<" -> ";
    test.displayStack();
  }
  int length = test.length();
  for(int i = 0 ; i < length ; i++)
  {
    tmp = test.pop();
    cout<<"removing "<<setw(3)<<tmp<<" -> ";
    test.displayStack();
  }
}
