#include <iostream>
#include<string>
using namespace std;

// Making a node struct containing a data int and a pointer
// to another node
struct Node { 
  std::string data; 
  Node *next; 
};

class LinkedList
{
    // Head pointer
    Node* head;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
    }

    // inserting elements (At start of the list)
    void insert(string val)
    {
      // make a new node
      Node* new_node = new Node;
      (new_node->data).assign(val);
      new_node->next = NULL;

      // If list is empty, make the new node, the head
      if (head == NULL)
        head = new_node;
      // else, make the new_node the head and its next, the previous
      // head
      else
      {
        new_node->next = head;
        head = new_node;
      }
    }

    // loop over the list. return true if element found
    bool search(string val)
    {
      Node* temp = head;
      while(temp != NULL)
      { 
        if ((temp->data).compare(val) == 0)
          return true;
        temp = temp->next;
      }
      return false;
    }

    
    void remove(string val)
    {
      // If the head is to be deleted
      if ((head->data).compare(val) == 0)
      {
        delete head;
        head = head->next;
        cout<<"Linked List Modified\n";
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if ((head->data).compare(val) == 0)
        {
          delete head;
          head = NULL;
          cout<<"Linked List Modified\n";
          return;
        }
        // else print, value not found
        cout << "Value not found!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      Node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if ((temp->next->data).compare(val) == 0)
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          cout<<"Linked List Modified\n";
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not found" << endl;
    }

    void display()
    {
      Node* temp = head;
      while(temp != NULL)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  LinkedList l;
  int choice;
  string name;

  while(true)
  {
    cout<<"ENTER YOUR CHOICE\n1: Add a name\n2: Delete a name\n3: Display List\n4: Exit\n";
    cin>>choice;
    if(choice == 4)
    {
      break;
    }
    else if(choice == 1)
    { 
     cout<<"Enter Name :";
      cin>>name;
      l.insert(name);
      cout<<"Linked List Modified : ";
      l.display();
    }
    else if(choice == 2)
    {
      cout<<"Enter Name :";
      cin>>name;
      l.remove(name);
      l.display();
    }
    else if(choice == 3)
    {
      l.display();
    }
    else{
      cout<<"Invalid Choice";
    } 
  }
}