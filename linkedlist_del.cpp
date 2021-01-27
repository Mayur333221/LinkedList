#include <bits/stdc++.h> 
using namespace std; 
  
// A linked list node 
class Node{ 
public: 
    int data; 
    Node* next; 
}; 


void delete_node(Node* &head, int key) 
{  
    Node* temp = head;  // storing head node 
    Node* prev = NULL; 
      
    // if head is to be deleted
    if (temp != NULL && temp->data == key) 
    { 
        head = temp->next; // Change head 
        delete temp;            // free old head memory 
        return; 
    } 
  
  // else search for the node to be deleted amd keep track of prev node 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key is not present in linked list 
    if (temp == NULL) 
        return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    // Free memory 
    delete temp; 
} 
  
  
void display(Node* node) 
{
    Node* temp=node; 
    while (temp != NULL)  
    { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
} 
// inserting at front(temporary)
void push(Node* &head, int data) 
{
	 
    Node* new_node = new Node(); 
    new_node->data = data;
    new_node->next = head; 
    head = new_node; 

}
int main() 
{ 
// creating a temp list
    Node* head = NULL; 
    push(head, 7); 
    push(head, 1); 
    push(head, 3); 
    push(head, 2); 
    delete_node(head, 1); 
    puts("\nLinked List after Deletion of 1: "); 
    display(head); 
      
    return 0; 
} 
  
