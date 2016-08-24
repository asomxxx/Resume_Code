// Single directional linked list implementation of queue

#include <iostream>
#include <stdlib.h>
using namespace std;


class Queue
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
  Queue()
  {head = NULL; len = 0;}

  int length()
  {return len;}

  bool push(int num)
  {
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    len++;
  }

  int pop()
  {
    if(head == NULL)
    {
      cout<<"ERROR: Queue is empty\n";
      return -99;  // really do need to go read the section on exceptions
    }
    else
    {
      int returnData;
      Node* tracker = head;
      Node* previous = NULL;
      while(tracker->next)
      {
        previous = tracker;
        tracker = tracker->next;
      }
      returnData = tracker->data;
      if(tracker==head)
      {
        delete head;
        head = NULL;
      }
      else
      {
        delete tracker;
        previous->next = NULL;
      }
      return returnData;
    }
  }
};

int main()
{
  Queue test;
  for(int i = 0 ; i<10 ; i++)
  {
    int tmp = (i * rand())%50;
    cout<<tmp<<" was pushed\n";
    test.push(tmp);
  }
  int L = test.length();
  for(int i = 0 ; i<L ; i++)
  {
    cout<<test.pop()<<endl;
  }
}
