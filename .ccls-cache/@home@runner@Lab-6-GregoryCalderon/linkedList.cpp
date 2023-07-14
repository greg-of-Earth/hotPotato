#include "linkedList.h"


#include <iostream>
using namespace std;


// constructor
LinkedList::LinkedList(int numNodes) {
  head = nullptr;
  potato = nullptr;
  length = 0;
  AddNode(numNodes);
}

// copy constructor 
LinkedList::LinkedList(const LinkedList& otherList) {
  //if not empty 
  if(otherList.head != nullptr) {
    // try to allocate memory 
    try{
      head = new Node(otherList.head->data); // copy head
      Node* currNode = head; // currNode points to head
      Node* otherCurrNode = otherList.head->next; 

      while(otherCurrNode != nullptr) { // while not end of list, make new node
        currNode->next = new Node(otherCurrNode->data);
        currNode = currNode->next; // update position 
        otherCurrNode = otherCurrNode->next;
        length++;
      }
      potato = otherList.potato;         
    }catch(bad_alloc& e)
    {
      ExceptionHandling("COPY");
    }
  }else {
    head = nullptr;
    potato = nullptr;
    length = 0;
  }
}

// copy assignment constructor
LinkedList& LinkedList::operator=(const LinkedList& orig) { 
  if(this != &orig) {  // self-assignment check 
    MakeEmpty();
  
  try {
      Node* origNode = orig.head;
      Node* prevNode = nullptr;
      while(origNode != nullptr) {
        Node* newNode = new Node(origNode->data); 
        if(prevNode == nullptr) { 
          head = newNode; 
          potato = head;
        } else {
          prevNode->next = newNode; 
        }
        prevNode = newNode; 
        origNode = origNode->next; // move to next node in source list
        length++;  // increment the length of the list  
      }
    } catch(bad_alloc& e) {
      // Exception handling for memory allocation failure
      ExceptionHandling("COPY");
    }
  }
  return *this;
}

// destructor
LinkedList::~LinkedList() {
  MakeEmpty();
}

//pre: get number of nodes to create from user 
//post: build linked list of nodes equal to user request
void LinkedList::AddNode(int numNodes) {  
  for(int i=1; i<=numNodes; i++) {
    Node* n_Node = new Node(i); // creates new node
    if(head == nullptr) { 
      head = n_Node; // if only the head node is in the list then the head node becomes the new node
      potato = head;
    }else {
      Node* currNode = head;
      while(currNode->next != nullptr) { //while it is not the last node
        currNode = currNode->next; // 'iterate' (traverse) the list
      }
      currNode->next = n_Node; // now at end of list, add the new node 
    }
    length++;  // increment the length of the list  
  }
}


//Pre: bad_alloc error triggered 
//Post: error message displayed, list will go out of scope and destructor will call MakeEmpty()
void LinkedList::ExceptionHandling(string errMsg) {
  if(errMsg == "COPY") {
    MakeEmpty();
  }
  cerr << errMsg << " MEMORY ERROR. LIST IS EMPTY\n";
}

//pre: get data of node to be deleted
//post: delete node that matches data and restructure list and reassign potato
void LinkedList::DeleteNode(int data) {
  Node* prevLocation = head;
  Node* deleteLocation = nullptr;
  if(data == head->data) { // if node to delete is head node then rearrange head
    deleteLocation = head; // save pointer to node
    head = head->next; // delete "first" node 
    potato = head;
  }
  else{
    while(deleteLocation ==nullptr) { // while potato not last node 
      if(data == prevLocation->next->data) { // if we find data 
        deleteLocation = prevLocation->next; // delete node become potato
        if(prevLocation->next->next != nullptr) {
          prevLocation->next = prevLocation->next->next; // if post connection valid create linkage
          potato = prevLocation->next;
        }else if(prevLocation->next->next == nullptr) { // at end of list
          prevLocation->next = nullptr; // prevLocation set as last node
          potato = head; // potato set to head 
        } 
      }
      prevLocation = prevLocation->next; // otherwise not found so move to next 
    }//end of while loop
  }//end of else is head is not the data needed
  delete deleteLocation; // delete the node
  length--; // shorten the list 
}

// clear the list by deleting each node
void LinkedList::MakeEmpty() {
  while(head!=nullptr) {
    Node* temp = head;
    head = temp->next;
    delete temp;
    length--; 
  }
  length = 0; 
}

// print whatever is in the list 
void LinkedList::Print() {
  Node* current = head;
  while(current!=nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << "\n\n";
}


int LinkedList::GetLength() const {
  return length;
}

//pre: get number of passes =  toTraverse
//post: return data of node potato lands on 
int LinkedList::TraverseList(int toTraverse) {
  //if not at the end of the list and still more nodes to traverse
  while(toTraverse > 0) {
    if(potato->next != nullptr) {
    potato = potato->next;
    toTraverse--; 
    }else {
      potato = head;
      toTraverse--;
    }
  } 
  
  return potato->data; // what is potato pointing to when
}
