#include <iostream>
#include <iomanip>
using namespace std;

class LinkedList
{
private:
  struct Node
  {
    int data;
    Node* next;
  };

  int len;
  Node* head;
public:
  //---------------------------------------------------------
  //  Constructor: Sets head == NULL (nullptr in c++11) and
  //              intilizes the length to 0
  //---------------------------------------------------------
  LinkedList()
  {head = NULL; len = 0;}

  //---------------------------------------------------------
  //  Getter: length()
  //  returns the length of the linked list
  //---------------------------------------------------------
  int length()
  {return len;}

  //---------------------------------------------------------
  //  Setter: append(int n)
  //  Adds a node with data == n at the end of the list
  //---------------------------------------------------------
  bool append(int n)
  {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    if(head)  //List is not empty
    {
      Node* tracker = head;
      while(tracker->next)  //Get to end of list
      {
        tracker = tracker->next;
      }
      tracker->next = newNode;  //Add new Node
      newNode->next = NULL;
      len++;
      return true;
    }
    else //List is empty
    {
      head = newNode;
      len++;
      return true;
    }
    return false;
  }

  //---------------------------------------------------------
  //  Setter: insert(int n)
  //  Adds a node with data == n at the front of the list
  //---------------------------------------------------------
  bool insert(int n) // if no position given add to front of list
  {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
    len++;
    return true;
  }

  //---------------------------------------------------------
  //  Setter: insert(int n , int pos)
  //  Adds a node with data == n at position pos
  //  Linked list is zero indexed
  //---------------------------------------------------------
  bool insert(int n , int pos)
  {
    if(len<pos) // Since the linked list is zero indexed the valid positions for insertion are given by len-1
    {
      cout<<"Cannot insert node at "<<pos<<" as the list is only "<<len<<" long\n";
      return false;
    }
    else
    {
      if(pos == 0)
      {
        return insert(n); // add to front of list using pre-existing function
      }
      Node* newNode = new Node;
      Node* tracker = head;
      Node* previous = NULL;
      newNode->data = n;
      for(int i = 0 ; i < pos ; i++) // get tracker to position
      {
        previous = tracker;
        tracker = tracker->next;
      }
      previous->next = newNode; //Insert the newNode;
      newNode->next = tracker;
      return true;
    }
    return false;
  }

  //---------------------------------------------------------
  //  output: display()
  //  outputs the list into terminal in the format
  //  head->node0->node1->...->nodeN->NULL
  //  used for checking that data is in the right place
  //---------------------------------------------------------
  void display()
  {
    if(head)
    {
      Node* tracker = head;
      cout<<"head->";
      while(tracker->next)
      {
        cout<<tracker->data<<"->";
        tracker = tracker->next;
      }
      cout<<tracker->data<<"->NULL"<<endl;
    }
    else
    {
      cout<<"List is empty\n";
    }

  }

  //---------------------------------------------------------
  //  Setter: remove(int pos)
  //  deletes the node at position pos
  //---------------------------------------------------------
  bool remove(int pos)
  {
    if(len<pos)
    {
      cout<<"Cannot remove node "<<pos<<" as the list is only "<<len<<" long\n";
      return false;
    }
    else
    {
      Node* tracker = head;
      Node* previous = NULL;
      if(pos == 0) //First node special case
      {
        head = tracker->next;
        delete tracker;
        return true;
      }
      for(int i = 0 ; i < pos ; i++)
      {
        previous = tracker;
        tracker = tracker->next;
      }
      //Once node is found remove tracker and point previous to followng node
      previous->next = tracker->next;
      delete tracker;
      return true;
    }
    return false;
  }

  //---------------------------------------------------------
  //  Setter: replace(int n , int pos)
  //  changes data at node pos to be == n
  //---------------------------------------------------------
  bool replace(int n, int pos)
  {
    if(pos>len)
    {
      cout<<"Cannot change node "<<pos<<" as the list is only "<<len<<" long\n";
      return false;
    }
    else
    {
      Node* tracker = head;
      for(int i = 0 ; i<pos ; i++)
      {
        tracker = tracker->next;
      }
      tracker->data = n;
      return true; 
    }

  }

};

int main()
{
  LinkedList list;
  list.insert(99,99);
  for(int i = 0 ; i < 5 ; i++)
  {
    list.append(i);
    //list.display();
  }
  for(int i = 0 ; i < 5 ; i++)
  {
    list.insert(i);
    //list.display();
  }
  list.insert(99 , 0);
  list.insert(99, 3);
  list.insert(88);
  list.display();
  list.remove(0);
  list.display();
}
