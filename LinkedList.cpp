#include<iostream>
using namespace std;
class Node {
    public:
    Node *next;
    Node *head;
    int value;
    
// Function to create a node
Node* createNode(int value) 
    {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }
//Function to add the node to the linked list
void addNode(Node*& head, int value)
{
    Node* newNode = createNode(value);
    if (head == NULL)
        {
            head = newNode;
        }
    else 
        {
         Node* curr = head;
                while (curr->next != NULL) 
                {
                    curr = curr->next;
                }
            curr->next = newNode;
        }
}
};
// function to delete the first occurrence of a node with the given value from the list
void deleteNode(Node*& head, int value) 
{
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) 
    {
        if (curr->value == value)
        {
            if (prev == NULL) 
            {
                head = curr->next;
            } else
                {
                    prev->next = curr->next;
                }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
   
}

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;
  Node NewNode; 
  // allocate 3 nodes in the heap
  one = new Node();
  two = new Node();
  three = new Node();

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // print the linked list value
  head = one;
  while (head != NULL) 
  {
    cout << head->value;
    head = head->next;
  }
  cout<<endl;

  NewNode.addNode(one, 4);
  // print  linked list after insertion
  head = one;
  while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
  cout<<endl;

  deleteNode(one, 2);

  // print linked list after deletion
     head = one;
    while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
  cout<<endl;

  return 0;
}
